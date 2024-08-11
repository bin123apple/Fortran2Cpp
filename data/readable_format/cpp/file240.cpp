#include <iostream>

class m1 {
public:
    static int i;

    static int ma_create_fun() {
        i = 1;
        return 2;
    }

    static int ma_create_new_fun() {
        i = 2;
        std::cout << "Hello from ma_create_new_fun" << std::endl;
        return 1;
    }
};

int m1::i = 0;

class m2 {
public:
    static int i;

    static void mb_create_sub() {
        i = 1;
        std::cout << "mb_create_sub called with i = " << i << std::endl;
    }

    static void mb_create_new_sub() {
        i = 2;
        std::cout << "mb_create_new_sub called with i = " << i << std::endl;
    }
};

int m2::i = 0;

int main() {
    int result;
    result = m1::ma_create_fun();
    std::cout << "Result of ma_create_fun: " << result << std::endl;
    result = m1::ma_create_new_fun();
    std::cout << "Result of ma_create_new_fun: " << result << std::endl;

    m2::mb_create_sub();
    m2::mb_create_new_sub();

    return 0;
}