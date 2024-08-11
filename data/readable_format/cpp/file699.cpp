#include <iostream>
#include <fstream>
#include <cstdio> // For remove()
#include <cassert>

void delevec(const std::string& scrpath, const std::string& filext) {
    std::string filePath1 = scrpath + "EVECFV" + filext;
    std::ifstream if1(filePath1);
    if (if1.good()) {
        if1.close();
        std::remove(filePath1.c_str());
    } else {
        if1.close();
    }

    std::string filePath2 = scrpath + "EVECSV" + filext;
    std::ifstream if2(filePath2);
    if (if2.good()) {
        if2.close();
        std::remove(filePath2.c_str());
    } else {
        if2.close();
    }
}

void createTestFile(const std::string& path) {
    std::ofstream ofs(path);
    ofs.close();
}

void testFileDeletion(const std::string& scrpath, const std::string& filext) {
    // Setup - create files to be deleted
    createTestFile(scrpath + "EVECFV" + filext);
    createTestFile(scrpath + "EVECSV" + filext);
    
    // Test deletion
    delevec(scrpath, filext);
    
    // Assertions
    std::ifstream testFile1(scrpath + "EVECFV" + filext);
    assert(!testFile1.good() && "EVECFV file was not deleted.");
    testFile1.close();

    std::ifstream testFile2(scrpath + "EVECSV" + filext);
    assert(!testFile2.good() && "EVECSV file was not deleted.");
    testFile2.close();

    std::cout << "All tests passed." << std::endl;
}

int main() {
    std::string scrpath = "./test/"; // Ensure this directory exists or create it as part of the setup
    std::string filext = ".txt";

    testFileDeletion(scrpath, filext);

    return 0;
}