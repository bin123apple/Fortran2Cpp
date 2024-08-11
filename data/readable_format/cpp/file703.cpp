#include <iostream>

// Define the class interface and implementation directly in the .cpp file
class geoutg_I {
public:
    virtual void geoutg(int IPRT) = 0; // Pure virtual function
    virtual ~geoutg_I() {} // Virtual destructor for a proper cleanup
};

class MyGeoutg : public geoutg_I {
public:
    void geoutg(int IPRT) override {
        std::cout << "IPRT = " << IPRT << std::endl;
    }
};

// Main function to test the implementation
int main() {
    MyGeoutg obj;
    obj.geoutg(5); // Should print "IPRT = 5"
    return 0;
}