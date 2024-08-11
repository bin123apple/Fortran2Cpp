#include <iostream>
#include <gtest/gtest.h>

// Simulate the Fortran interface with an abstract class in C++
class IotkRead {
public:
    virtual void read(int file_handle, int& data) = 0;  // Pure virtual function for reading int
    virtual void read(int file_handle, float& data) = 0; // Pure virtual function for reading float
};

// Concrete class implementing the IotkRead interface
class IotkReadImpl : public IotkRead {
public:
    void read(int file_handle, int& data) override {
        // Dummy implementation for testing
        data = 42;
    }

    void read(int file_handle, float& data) override {
        // Dummy implementation for testing
        data = 3.14f;
    }
};

// Test fixture for IotkReadImpl
class IotkReadImplTest : public ::testing::Test {
protected:
    IotkReadImpl iotkReader; // Test instance of IotkReadImpl
};

// Test case for reading int
TEST_F(IotkReadImplTest, HandlesIntRead) {
    int data;
    iotkReader.read(0, data); // Using 0 as a dummy file handle
    EXPECT_EQ(data, 42);
}

// Test case for reading float
TEST_F(IotkReadImplTest, HandlesFloatRead) {
    float data;
    iotkReader.read(0, data); // Using 0 as a dummy file handle
    EXPECT_FLOAT_EQ(data, 3.14f);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}