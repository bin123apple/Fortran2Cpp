#include <iostream>

class Orders {
public:
    double doubleOrder(double x) {
        return 2 * x;
    }

    int integerOrder(int x) {
        return 2 * x;
    }

    float realOrder(float x) {
        return 2 * x;
    }
};

int main() {
    Orders orders;
    
    // Test doubleOrder
    double dtest = 2.0;
    std::cout << "doubleOrder(2.0) = " << orders.doubleOrder(dtest) << std::endl;
    
    // Test integerOrder
    int itest = 2;
    std::cout << "integerOrder(2) = " << orders.integerOrder(itest) << std::endl;
    
    // Test realOrder
    float rtest = 2.0f;
    std::cout << "realOrder(2.0f) = " << orders.realOrder(rtest) << std::endl;

    return 0;
}