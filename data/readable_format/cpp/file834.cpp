#include <iostream>
#include <vector>
#include <stdexcept>

// Abstract base class for general function
class GeneralFunc {
public:
    virtual void operator()(const std::vector<int>& arr) = 0;
    virtual void operator()(const std::vector<std::vector<int>>& arr) = 0;
};

// Derived class for func_dim1
class FuncDim1 : public GeneralFunc {
public:
    void operator()(const std::vector<int>& arr) override {
        std::cout << "inside func_dim1" << std::endl;
        std::cout << "Shape: [1 x " << arr.size() << "]" << std::endl;
        for (const auto& val : arr) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    void operator()(const std::vector<std::vector<int>>& arr) override {
        // Not intended for use with 2D arrays, but must be implemented.
        throw std::runtime_error("FuncDim1 is not compatible with 2D arrays.");
    }
};

// Derived class for func_dim2
class FuncDim2 : public GeneralFunc {
public:
    void operator()(const std::vector<int>& arr) override {
        // Not intended for use with 1D arrays, but must be implemented.
        throw std::runtime_error("FuncDim2 is not compatible with 1D arrays.");
    }

    void operator()(const std::vector<std::vector<int>>& arr) override {
        std::cout << "inside func_dim2" << std::endl;
        std::cout << "Shape: [" << arr.size() << " x " << arr.front().size() << "]" << std::endl;
        for (const auto& row : arr) {
            for (const auto& val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }
};

// Main program, for demonstration or testing
int main() {
    FuncDim1 funcDim1;
    FuncDim2 funcDim2;

    std::vector<int> dim1 = {1, 2};
    std::vector<std::vector<int>> dim2 = {{1, 2}, {3, 4}};

    std::cout << ">> output of func_dim1 - array:" << std::endl;
    funcDim1(dim1); // Demonstrating funcDim1

    std::cout << ">> output of func_dim2 - array:" << std::endl;
    funcDim2(dim2); // Demonstrating funcDim2

    return 0;
}