import rclpy
from rclpy.node import Node
class PersonNode(Node):
    def __init__(self, name_value:str, age_value:int):
        super().__init__(node_name=name_value)  # Initialize the Node with the name 'PersonNode'
        self.name = name_value
        self.age = age_value
        print(f'PersonNode created with name: {self.name} and age: {self.age}')
    def eat(self,food:str):
        self.get_logger().info(f'{self.name} who is {self.age} years old is eating {food}.')

def main():
    rclpy.init()
    node = PersonNode('thb', 30)
    node.eat('apple')
    node2 = PersonNode('sbthb', 25)
    node2.eat('banana')
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':    
    main()
