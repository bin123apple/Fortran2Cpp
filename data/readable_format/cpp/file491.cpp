#include <iostream>

class Foo {
public:
    struct FooType {
        // This can hold member variables or functions if needed
    };

    static float someFunction(float inParam, float& inOutParam, float& outParam) {
        float returnValue = 0.0f; // Example calculation for returnValue
        // Assuming some operations here since the original code doesn't specify them
        outParam = inParam * 2.0f;
        inOutParam += 1.0f;
        returnValue = outParam + inOutParam;
        return returnValue;
    }
};

int main() {
    float inParam = 5.0f;
    float inOutParam = 3.0f;
    float outParam = 0.0f; // Will be set by someFunction

    // Call the function
    float result = Foo::someFunction(inParam, inOutParam, outParam);

    // Output the results
    std::cout << "Result: " << result << std::endl;
    std::cout << "InOutParam: " << inOutParam << std::endl;
    std::cout << "OutParam: " << outParam << std::endl;

    return 0;
}