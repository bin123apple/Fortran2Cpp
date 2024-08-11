#include <iostream>
#include <typeinfo>
#include <cxxabi.h>

int main() {
    double i;
    int status;
    char *real_name = abi::__cxa_demangle(typeid(i).name(), 0, 0, &status);
    std::cout << real_name << std::endl;
    std::free(real_name);
    return 0;
}