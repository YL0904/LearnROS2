import rclpy
from rclpy.node import Node
from status_interfaces.msg._system_status import SystemStatus  # noqa: F401
import psutil
import platform

class SystemStatusPublisher(Node):
    def __init__(self,node_name,pub_name):
        super().__init__(node_name)
        self.status_publisher = self.create_publisher(
            SystemStatus, pub_name, 10)
        self.timer = self.create_timer(1.0, self.timer_callback)
    def timer_callback(self):
        '''
        builtin_interfaces/Time stamp #记录时间戳
        string host_name #主机名字
        float32 cpu_percent #CPU使用率
        float32 memory_percent #内存使用率
        float32 memory_total #内存总大小
        float32 memory_avaliable #内存剩余量
        float64 net_sent #网络数据发送总量
        float64 net_recv #网络数据接收总量
        '''        
              
        cpu_percent = psutil.cpu_percent()
        memory_info = psutil.virtual_memory()
        net_io_counters = psutil.net_io_counters()
        msg = SystemStatus()
        msg.stamp = self.get_clock().now().to_msg()
        msg.host_name = platform.node()
        msg.cpu_percent = cpu_percent
        msg.memory_total = float(memory_info.total)
        msg.memory_avaliable = float(memory_info.available)
        msg.net_sent = float(net_io_counters.bytes_sent /1024 /1024)
        msg.net_recv = float(net_io_counters.bytes_recv /1024 /1024)
        self.get_logger().info(f'Publishing system status: msg{str(msg)}')
        self.status_publisher.publish(msg)
def main(args=None):
    rclpy.init(args=args)
    system_status_publisher = SystemStatusPublisher(
        'system_status_publisher', 'system_status')
    rclpy.spin(system_status_publisher)
    rclpy.shutdown()