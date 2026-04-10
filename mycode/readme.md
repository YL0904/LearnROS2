## L2
修改环境变量改变打印日至
```bash
export RCUTILS_CONSOLE_OUTPUT_FORMAT="[{severity}] [{time}] [{name}]: {message}"
```

根据当前文件夹中pkg构建包
```bash
colcon build
```
source指令直接修改环境变量。他会同时修改PYTHONPATH和AmentPATH，使得可以通过`python_node`和`ros2 run demo_python_pkg python_node`执行包
```bash
source ~/setup.bash
```
 python类（面向对象编程）
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
类的继承
```python
class Person(父类名):
    def __init__(self,......)
        super().__init__(父类初始化需要的参数)
```