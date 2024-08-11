#include <gtest/gtest.h>
#include <string>

// Assuming the content of MFAnimal (Base Class)
class TFAnimal {
public:
    virtual std::string say() const = 0; // Making it a pure virtual function for demonstration
    virtual ~TFAnimal() = default; // Virtual destructor for proper cleanup
};

// Derived Class
class TFCat : public TFAnimal {
public:
    // Override the say function from the base class
    std::string say() const override {
        return "Myaw";
    }
};

// Unit Test
TEST(TFCatTest, SayMethod) {
    TFCat cat;
    EXPECT_EQ("Myaw", cat.say());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}