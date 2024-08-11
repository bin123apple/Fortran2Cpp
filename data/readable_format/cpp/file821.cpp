#include <iostream>
#include <string>

class UnitValue {
public:
    float value;
    std::string unit;

    UnitValue(float val = 0.0, std::string unt = "") : value(val), unit(unt) {}

    // Overload the + operator
    UnitValue operator+(const UnitValue& other) const {
        // Assuming both values are in the same unit for simplicity
        return UnitValue(value + other.value, unit);
    }
};

int main() {
    UnitValue uv1(10.0, "kg"), uv2(20.0, "kg");
    UnitValue result = uv1 + uv2;

    std::cout << "Result: " << result.value << " " << result.unit << std::endl;
    return 0;
}