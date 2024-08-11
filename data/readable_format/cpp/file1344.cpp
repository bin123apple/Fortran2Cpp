#include <gtest/gtest.h>
#include <fstream>
#include <unordered_map>

std::unordered_map<int, std::fstream> fileMap;

void closeUnit(int unitnum) {
    auto it = fileMap.find(unitnum);
    if (it != fileMap.end()) {
        if (it->second.is_open()) {
            it->second.close();
            // Corrected multiline string
            std::cout << "File with unit number " << unitnum << " closed successfully." << std::endl;
        } else {
            std::cerr << "Error: File with unit number " << unitnum << " is not open." << std::endl;
        }
        fileMap.erase(it); // Optionally remove the file from the map after closing
    } else {
        std::cerr << "Error: No file associated with unit number " << unitnum << "." << std::endl;
    }
}

// Test fixture for file closing tests
class FileCloseTest : public ::testing::Test {
protected:
    void SetUp() override {
        int testUnitNum = 1;
        fileMap[testUnitNum].open("testfile_cpp.txt", std::fstream::out);
        ASSERT_TRUE(fileMap[testUnitNum].is_open());
    }

    void TearDown() override {
        int testUnitNum = 1;
        if (fileMap.find(testUnitNum) != fileMap.end() && fileMap[testUnitNum].is_open()) {
            fileMap[testUnitNum].close();
        }
        fileMap.erase(testUnitNum);
        remove("testfile_cpp.txt");
    }
};

TEST_F(FileCloseTest, ClosesFileCorrectly) {
    int testUnitNum = 1;
    closeUnit(testUnitNum);

    ASSERT_EQ(fileMap.find(testUnitNum), fileMap.end());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}