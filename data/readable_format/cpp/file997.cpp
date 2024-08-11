#include <iostream>
#include <gtest/gtest.h>

// Define the TreeNode class directly in this file
class TreeNode {
public:
    ~TreeNode() {
        // Destructor code here, if needed
    }
};

// Define the DestroyNode function
void DestroyNode(TreeNode*& theNode, bool& lstatus) {
    if (theNode != nullptr) {
        delete theNode;
        theNode = nullptr;
        lstatus = true; // Operation successful
    } else {
        lstatus = false; // Operation failed, theNode was already null
    }
}

// Unit tests for the TreeNode and DestroyNode functionality
TEST(TreeNodeTest, DestroyUninitialized) {
    TreeNode* theNode = nullptr; // Start with an uninitialized pointer
    bool lstatus = false;
    DestroyNode(theNode, lstatus);
    EXPECT_EQ(lstatus, false); // Expect failure since theNode is uninitialized.
}

TEST(TreeNodeTest, DestroyInitialized) {
    TreeNode* theNode = new TreeNode(); // Dynamically allocate a TreeNode
    bool lstatus = false;
    DestroyNode(theNode, lstatus);
    EXPECT_EQ(lstatus, true); // Expect success since theNode was initialized.
    EXPECT_EQ(theNode, nullptr); // theNode should now be nullptr.
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}