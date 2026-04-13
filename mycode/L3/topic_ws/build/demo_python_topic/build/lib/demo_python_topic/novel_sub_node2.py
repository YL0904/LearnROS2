import rclpy
from rclpy.node import Node
from example_interfaces.msg import String
from queue import Queue
import subprocess
import threading
import time

class NovelSubNode(Node):
    def __init__(self,node_name):
        super().__init__(node_name)
        self.novel_queue_ = Queue() # 创建一个队列来存储小说内容
        self.get_logger().info(f"{node_name} is created")
        self.novel_subscriber = self.create_subscription(String, 'novel', self.novel_callback, 10)
        self.speaker_thread = threading.Thread(target=self.speak_novel)
        self.speaker_thread.start() # 启动朗读线程
    def novel_callback(self,msg):
        self.novel_queue_.put(msg.data) # 将接收到的小说内容放入队列中
    def speak_novel(self):
        while rclpy.ok():
            if self.novel_queue_.qsize() > 0: # 如果队列中有小说内容
                text = self.novel_queue_.get() # 从队列中获取小说内容
                subprocess.run(
                    [
                        'spd-say',
                        '-l', 'cmn',
                        '-o', 'espeak-ng',
                        '-t', 'female1',
                        '-r', '-25',
                        '-p', '-15',
                        '-w',
                        text,
                    ],
                    check=False,
                )
                self.get_logger().info(f"朗读小说内容: {text}")
            else:
                time.sleep(0.1) # 如果队列为空，稍微等待一下
def main(args=None):
    rclpy.init(args=args)
    node = NovelSubNode("novel_sub")
    rclpy.spin(node)
    rclpy.shutdown()
