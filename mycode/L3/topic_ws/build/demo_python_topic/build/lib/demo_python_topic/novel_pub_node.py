import rclpy
from rclpy.node import Node
import requests
from example_interfaces.msg import String
from queue import Queue

class NovelPubNode(Node):
    def __init__(self,node_name):
        super().__init__(node_name)
        self.get_logger().info(f"{node_name} is created")
        self.novel_publisher = self.create_publisher(String, 'novel', 10)
        self.novel_queue = Queue() # 创建一个队列来存储小说内容
        self.create_timer(1.0, self.publish_novel) # 每隔1秒发布一次小说内容,调用publish_novel函数回调函数
    def publish_novel(self):
        if self.novel_queue.qsize() > 0:
            line = self.novel_queue.get() # 从队列中获取一行小说内容
            msg = String()
            msg.data = line
            self.novel_publisher.publish(msg) # 发布小说内容
            self.get_logger().info(f'Published novel line: {line}')
    def download(self,url):
        response = requests.get(url)
        response.encoding = 'utf-8'
        text = response.text
        self.get_logger().info(f'{url}:{len(text)}')
        for line in text.splitlines():
            self.novel_queue.put(line) # 将小说内容逐行放入队列中
def main(args=None):
    rclpy.init(args=args)
    node = NovelPubNode("novel_pub")
    node.download('http://0.0.0.0:8000/novel1.txt')
    rclpy.spin(node)
    rclpy.shutdown()
