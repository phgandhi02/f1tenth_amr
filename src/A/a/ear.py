import rclpy
from rclpy.node import Node
from std_msgs.msg import String


class node_2(Node):

    def __init__(self):
        super().__init__('node_2')
        self.subscription = self.create_subscription(
            String,
            'topic',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning

    def listener_callback(self, msg):
        self.get_logger().info('I heard: "%s"' % msg.data)


def main(args=None):
    rclpy.init(args=args)

    node_2 = node_2()

    rclpy.spin(node_2)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    node_2.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()