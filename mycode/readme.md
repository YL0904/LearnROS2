## L2
### 修改环境变量改变打印日至
```bash
export RCUTILS_CONSOLE_OUTPUT_FORMAT="[{severity}] [{time}] [{name}]: {message}"
```

### 根据当前文件夹中pkg构建包
```bash
colcon build
```

### source指令直接修改环境变量。他会同时修改PYTHONPATH和AmentPATH，使得可以通过`python_node`和`ros2 run demo_python_pkg python_node`执行包
```bash
source ~/setup.bash
```

### python类（面向对象编程）
```python
class Person:
    def __init__(self,属性1:str,属性2:int)
        self.属性1 = age #用于全部方法的变量
        self.属性2 = name
    def eat(self,food_name:str)
        print(f'我叫{self.name},今年{self.age},我正在吃{food_name}')
Person1 = Person('thb','1') #实例化
Person1.eat('shit') #.可以调用实例的方法
```

### 类的继承
```python
class Person(父类名):
    def __init__(self,......)
        super().__init__(父类初始化需要的参数)
```

### 回调函数：将一个函数作为参数传给某一个方法或函数，当后者结束时调用回调函数。
```python
class Download():
    def download(self,url,callback_world_count):
        print(f'线程{threading.get_ident()},正在下载{url}...')
        response = requests.get(url)
        response.encoding = 'utf-8'
        callback_world_count(url,response.text)
    def start_download(self,url,callback_world_count):
        # self.download(url,callback_world_count)
        thread = threading.Thread(target=self.download,args=(url,callback_world_count)) #创建线程对象
        thread.start() #启动线程
def world_count(url,result):
    '''
    回调函数，统计单词数量
    '''
    print(f'{url}:{len(result)}--{result[0:5]}')
```

## L3
### Topic 通信基础
L3 主要开始学习 ROS 2 的话题通信模型，也就是 Publisher 和 Subscriber 的使用方式。话题通信适合单向连续数据传输，比如文本、传感器数据、状态信息等。

### Python 话题发布与订阅
在 `topic_ws` 中我使用 `demo_python_topic` 包练习了 Python 版本的话题通信。

- 发布者节点通过 `create_publisher` 创建发布器
- 订阅者节点通过 `create_subscription` 创建订阅器
- 发布和订阅双方必须使用同一个话题名和同一个消息类型
- 定时任务可以通过 `create_timer` 周期性触发回调函数

发布者核心思路：
- 使用 `Queue` 缓存待发送的数据
- 先通过 `requests` 下载小说文本
- 再通过定时器每秒取一行发布到 `novel` 话题

订阅者核心思路：
- 在回调函数中接收字符串消息
- 将接收到的数据放入队列
- 单独开启线程调用 `espeakng` 进行语音朗读

这一部分让我理解了 ROS 2 中“回调 + 队列 + 定时器 + 多线程”组合使用的基本方式。

### 自定义消息接口
在 `topic_project` 中我学习了如何创建一个自定义接口包 `status_interfaces`，并定义了自己的消息类型 `SystemStatus.msg`。

这个消息中包含：
- 时间戳 `stamp`
- 主机名 `host_name`
- CPU 使用率 `cpu_percent`
- 内存使用率 `memory_percent`
- 内存总量 `memory_total`
- 剩余内存 `memory_avaliable`
- 网络发送量 `net_sent`
- 网络接收量 `net_recv`

自定义消息的关键点：
- 消息接口文件要放在 `msg/` 目录下
- 消息定义文件使用 `.msg` 格式，不是 Python 类，也不是 C++ 类
- 虽然业务节点可以用 Python 写，但自定义接口包通常仍然使用 `ament_cmake`
- `CMakeLists.txt` 中通过 `rosidl_generate_interfaces()` 生成接口代码
- `package.xml` 中要正确声明 `rosidl_default_generators`、`builtin_interfaces` 等依赖

### Python 中使用自定义消息
虽然我主要使用 Python 编写节点，但这不影响使用自定义消息。ROS 2 会根据 `.msg` 文件自动生成 Python 版本接口。

正确的导入方式是：
```python
from status_interfaces.msg import SystemStatus
```

这里我学到一个重要概念：
- `.msg` 是语言无关的接口描述文件
- ROS 2 会自动生成 C、C++、Python 等多语言接口绑定
- 所以“自定义消息”本质上不是用 C++ 定义的，而是用 ROS 2 接口语法定义的

### 状态发布节点练习
在 `status_publisher` 包中，我编写了 `sys_status_pub.py`，周期性采集本机系统状态并发布到话题中。

这个节点练习了以下内容：
- 使用 `psutil` 获取 CPU、内存、网络统计信息
- 使用 `platform.node()` 获取主机名
- 使用 `self.get_clock().now().to_msg()` 生成 ROS 时间戳
- 将系统监控数据封装成自定义消息并发布

### 这一部分踩到的坑
L3 这一部分让我真正体会到接口包配置要非常严谨，常见错误主要有：

1. `rosidl_generate_interfaces()` 中消息路径不能写错  
例如不能写成以 `/msg/...` 开头的错误绝对路径，应写成相对路径 `msg/SystemStatus.msg`

2. `.msg` 文件中的消息类型名大小写必须正确  
例如 `builtin_interfaces/Time` 不能写成 `builtin_interfaces/time`

3. `package.xml` 必须是合法 XML，且依赖名不能拼错  
例如：
- `builtin_interfaces` 不能写成 `builtin_interface`
- `rosidl_default_generators` 不能写成 `rosidl_default_genterators`

4. Python 节点给 ROS 消息赋值时要注意字段类型  
如果 `.msg` 中定义的是 `float32/float64`，Python 里最好显式转成 `float`，否则在转换时可能报错

5. 改过消息名之后要注意清理旧的构建产物  
否则 `build/` 和 `install/` 中可能同时残留旧接口和新接口，容易造成混乱

### 当前理解
L3 学完之后，我对 ROS 2 话题通信的理解更清晰了：

- 话题适合持续广播型数据
- Python 节点开发效率高，适合快速实验
- 自定义消息接口是 ROS 2 工程组织中的重要基础
- 接口包和业务节点包分开管理会更清晰
- 即使不会 C++，也可以通过 `ament_cmake + .msg` 的方式完成自定义接口开发
