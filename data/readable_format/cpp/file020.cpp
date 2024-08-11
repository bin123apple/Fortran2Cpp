#include <gtest/gtest.h>
#include <memory>
#include <vector>

// Definition of the Foo class
class Foo {
public:
    int bar;
    Foo(int value = 99) : bar(value) {} // Constructor initializes 'bar' with 99 by default
};

// Test fixture for Foo-related tests
class FooTest : public ::testing::Test {
protected:
    std::vector<std::unique_ptr<Foo>> foobar;
    std::vector<std::unique_ptr<Foo>> some_local_object;

    void SetUp() override {
        // Setup code similar to the main program logic
        foobar.resize(10);
        for (auto &elem : foobar) {
            elem = std::make_unique<Foo>(); // Allocate each Foo with default value
        }

        some_local_object.resize(10);
        for (size_t i = 0; i < foobar.size(); ++i) {
            some_local_object[i] = std::make_unique<Foo>(*foobar[i]); // Copy each Foo
        }
    }
};

// Test case to verify the 'bar' values in 'some_local_object'
TEST_F(FooTest, VerifyBarValues) {
    for (const auto& elem : some_local_object) {
        EXPECT_EQ(elem->bar, 99) << "Bar value is not 99";
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}