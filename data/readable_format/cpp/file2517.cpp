#include <iostream>
#include <vector>
#include <cmath>
#include <functional>

class ProcPointer {
public:
    float a;
    std::function<void(std::vector<float>&)> my_pointer;

    ProcPointer() : a(0.0f), my_pointer(nullptr) {}

    static void sub(std::vector<float>& x) {
        for (size_t i = 0; i < x.size(); ++i) {
            x[i] = std::pow(0.5, i + 1);
        }
    }
};

int main() {
    ProcPointer pp;
    pp.my_pointer = ProcPointer::sub;

    std::vector<float> data = {1.0f, 2.0f, 3.0f};

    if (pp.my_pointer) {
        pp.my_pointer(data);
    }

    for (const auto& val : data) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}