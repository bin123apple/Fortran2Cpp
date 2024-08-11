#include <string>
#include <iostream>
#include <cassert>

void stripPath(const std::string& fnam2, std::string& fnam, std::string& path, int& iflag) {
    iflag = 0;
    std::size_t pos = fnam2.rfind('/');
    if (pos != std::string::npos) {
        iflag = static_cast<int>(pos) + 1;
        fnam = fnam2.substr(pos + 1);
        path = fnam2.substr(0, pos+1);
    } else {
        fnam = fnam2;
        path = "";
    }
}

int main() {
    std::string fnam2, fnam, path;
    int iflag;

    // Test 1
    fnam2 = "/path/to/the/file.txt";
    stripPath(fnam2, fnam, path, iflag);
    assert(fnam == "file.txt");
    assert(path == "/path/to/the/");
    assert(iflag == 13);
    std::cout << "Test 1 passed." << std::endl;

    // Test 2
    fnam2 = "file.txt";
    stripPath(fnam2, fnam, path, iflag);
    assert(fnam == "file.txt");
    assert(path.empty());
    assert(iflag == 0);
    std::cout << "Test 2 passed." << std::endl;

    // Test 3
    fnam2 = "/path/to/multiple/slashes/file.txt";
    stripPath(fnam2, fnam, path, iflag);
    assert(fnam == "file.txt");
    assert(path == "/path/to/multiple/slashes/");
    assert(iflag == 26);
    std::cout << "Test 3 passed." << std::endl;

    return 0;
}