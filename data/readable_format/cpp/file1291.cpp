// Ensure your compiler command includes -std=c++17 or later, e.g., g++ -std=c++17 test.cpp -lgtest -lgtest_main -pthread -o testExecutable

#include <gtest/gtest.h>
#include <fstream>

// Since there was an issue with recognizing 'std::filesystem', let's directly check file existence using fstream for this example.
bool fileExists(const std::string& name) {
    std::ifstream f(name.c_str());
    return f.good();
}

// Test Fixture for File Handling Tests
class FileHandlingTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test...
    }

    void TearDown() override {
        // Cleanup code after each test...
        std::remove("99"); // Directly attempt to remove the file without checking for existence
    }
};

TEST_F(FileHandlingTest, FileCreationAndDeletion) {
    // This test creates a file, checks its existence, then deletes it and checks again.
    std::ofstream fileUnit("99");
    ASSERT_TRUE(fileUnit.good()) << "Failed to create file '99'";
    fileUnit.close();

    ASSERT_TRUE(fileExists("99")) << "File '99' should exist after creation.";

    std::remove("99"); // Delete the file

    ASSERT_FALSE(fileExists("99")) << "File '99' should not exist after deletion.";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}