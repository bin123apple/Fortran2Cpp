#include <iostream>

class p_vec {
public:
    virtual ~p_vec() {
        std::cout << "p_vec destructor called" << std::endl;
    }
};

class bar : public p_vec {
public:
    ~bar() override {
        std::cout << "bar destructor called" << std::endl;
    }
};

int main() {
    std::cout << "Creating a p_vec." << std::endl;
    p_vec* myVec = new p_vec();
    std::cout << "Destroying a p_vec." << std::endl;
    delete myVec;
    
    std::cout << "Creating a bar." << std::endl;
    bar* myBar = new bar();
    std::cout << "Destroying a bar." << std::endl;
    delete myBar;
    
    return 0;
}