#include <iostream>
#include <string>
#include <memory>

int main() {
    std::unique_ptr<std::string> s = std::make_unique<std::string>("123  ");
    int l2 = s->length(); // Obtain the length of the string

    std::cout << "Length of the string: " << l2 << std::endl;

    return 0;
}