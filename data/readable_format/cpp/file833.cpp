#include <cassert>
#include <iostream>

// Directly include the class definition in the same file
class TEST {
public:
    struct all_type {
        struct info_type {
            int value;
        } info;
    };

    class any_type {
    private:
        struct info_type {
            int value;
        } info;
    public:
        void setValue(int val) { info.value = val; }
        int getValue() const { return info.value; }
    };
};

int main() {
    // Testing all_type
    TEST::all_type obj1;
    obj1.info.value = 5;
    assert(obj1.info.value == 5);
    std::cout << "all_type test passed." << std::endl;

    // Testing any_type
    TEST::any_type obj2;
    obj2.setValue(10);
    assert(obj2.getValue() == 10);
    std::cout << "any_type test passed." << std::endl;

    return 0;
}