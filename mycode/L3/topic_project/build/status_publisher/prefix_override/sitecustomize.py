import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/nrrr/ros2Learn/mycode/L3/topic_project/install/status_publisher'
