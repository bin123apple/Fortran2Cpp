#include <iostream>
#include <string>

int main() {
    std::string c = "Hello, "
                    "world!";
    
    if (c != "Hello, world!") {
        return 1;
    }

    return 0;
}