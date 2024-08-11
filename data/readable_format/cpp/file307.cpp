#include <iostream>
#include <memory>
#include <gtest/gtest.h>

// Base class equivalent to the Fortran base_mod module
class BaseType {
public:
    virtual std::unique_ptr<BaseType> clone() const = 0;
    virtual ~BaseType() = default; // Ensure proper cleanup
};

// Derived class equivalent to the Fortran r_mod module
class RType : public BaseType {
public:
    // Override the clone method to return a copy of the current object
    std::unique_ptr<BaseType> clone() const override {
        return std::make_unique<RType>(*this);
    }
};

// Unit test using Google Test framework
TEST(BaseModTest, CloneTest) {
    RType original;
    auto cloned = original.clone();
    
    // The dynamic_cast checks if 'cloned' can be successfully cast to 'RType*'
    // This serves as a way to verify that the clone operation returns the correct type
    auto r_cloned = dynamic_cast<RType*>(cloned.get());
    EXPECT_NE(r_cloned, nullptr);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}