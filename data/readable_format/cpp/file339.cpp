#include <iostream>

class M1 {
public:
    void bar() {
        std::cout << "In bar" << std::endl;
    }

    void bar_none(int i) {
        std::cout << "In bar_none with i = " << i << std::endl;
    }

    void none_bar(float x) {
        std::cout << "In none_bar with x = " << x << std::endl;
    }
};

int main() {
    M1 m1;
    m1.bar();
    m1.bar_none(5);
    m1.none_bar(3.14f);

    // Optional: Add return 0 at the end of main to indicate successful execution.
    return 0;
}