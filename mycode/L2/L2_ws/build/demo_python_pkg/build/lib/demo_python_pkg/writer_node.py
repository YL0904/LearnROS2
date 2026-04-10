import rclpy
from rclpy.node import Node
class writerNode(Node):
    def __init__(self,book:str, name_value:str, age_value:int):
        super().__init__(node_name=book)  # Call the constructor of the parent class (PersonNode)
        self.book = book
        self.name = name_value
        self.age = age_value
    def writer_eat(self,food:str):
        self.get_logger().info(f'{self.name} who is {self.age} years old is eating {food} while \
writing {self.book}.')

def main():
    rclpy.init()
    node = writerNode('thbbook', 'thb', 30)
    node.writer_eat('apple')
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':    
    main()