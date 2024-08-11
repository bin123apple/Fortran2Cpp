#include <iostream>
#include <memory>
#include <gtest/gtest.h>

class Node {
public:
    int data;
    std::unique_ptr<Node> next;

    Node(int val) : data(val), next(nullptr) {}
    Node(const Node& other) = delete; // prevent copy construction
    Node& operator=(const Node& other) = delete; // prevent copy assignment
    ~Node() = default;

    friend std::unique_ptr<Node> add_nodes(const Node& node1, const Node& node2);
};

std::unique_ptr<Node> add_nodes(const Node& node1, const Node& node2) {
    return std::make_unique<Node>(node1.data + node2.data);
}

TEST(NodeTest, AddNodes) {
    Node node1(10);
    Node node2(20);

    auto sumNode = add_nodes(node1, node2);

    EXPECT_EQ(sumNode->data, 30) << "Sum of node1 and node2 should be 30";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}