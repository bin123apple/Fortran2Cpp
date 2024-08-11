#include <iostream>
#include <cstddef> // for std::size_t

extern "C" {
    void myFunction(float& f, std::size_t d) {
        std::cout << "f=" << f << " d=" << d << std::endl;
    }
}

// Example usage
/*
int main() {
    float f = 1.23f;
    std::size_t d = 456;
    
    myFunction(f, d);

    return 0;
}
*/