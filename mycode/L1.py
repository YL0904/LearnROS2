import rclpy
from rclpy.node import Node
def main(args=None):
    rclpy.init()
    node = Node('MyNode')
    # [INFO] [MyNode]: Hello from MyNode!
    node.get_logger().info('Hello from MyNode!')
    node.get_logger().warn('This is a warning message.')
    rclpy.spin(node) # Keeps the node running until it is shut down
    rclpy.shutdown()
if __name__ == '__main__':
    main()
    