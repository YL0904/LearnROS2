## L2
修改环境变量改变打印日至
```
export RCUTILS_CONSOLE_OUTPUT_FORMAT="[{severity}] [{time}] [{name}]: {message}"
```

根据当前文件夹中pkg构建包
```
colcon build
```

source指令直接修改环境变量。他会同时修改PYTHONPATH和AmentPATH，使得可以通过`python_node`和`ros2 run demo_python_pkg python_node`执行包
```
source ~/setup.bash
```
