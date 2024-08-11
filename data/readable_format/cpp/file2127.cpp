#include <iostream>
#include <gtest/gtest.h>

void foo() {
    std::cout << "foo() called";
}

// Redirects std::cout to a stringstream to capture the output
class CoutRedirect {
public:
    CoutRedirect(std::streambuf* new_buffer) : old(std::cout.rdbuf(new_buffer)) {}
    ~CoutRedirect() { std::cout.rdbuf(old); }
private:
    std::streambuf* old;
};

TEST(FooTest, BasicTest) {
    std::stringstream buffer;
    CoutRedirect redirect(buffer.rdbuf());

    foo();

    std::string output = buffer.str();
    EXPECT_EQ(output, "foo() called");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}