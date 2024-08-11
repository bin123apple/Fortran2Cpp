#include <iostream>
#include <string>
#include <cstdlib>  // for abort()

int main() {
    std::string x = "12345";
    size_t i = x.find("blablabl");
    if (i != std::string::npos) {
        std::abort();
    }
    return 0;
}