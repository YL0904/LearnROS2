import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/nrrr/ros2Learn/mycode/L2/L2_ws/install/demo_python_pkg'
