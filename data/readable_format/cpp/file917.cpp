#include <iostream>
#include <string>

// Assuming the existence of ExampleParameter in the ModExample2 namespace
// For demonstration purposes, let's define it here directly.
const float ExampleParameter = 1.0f;

namespace ModExample2 {

    // Module-level constants can be represented as constexpr variables
    constexpr char NameMod[] = "ModExample2";

    void example_iroutine(float InputVar, float& OutputVar, float& InputOutputVar) {
        // Local constant, combining strings
        const std::string NameSub = std::string(NameMod) + "::example_iroutine";

        std::cout << NameSub << ": documented executable statements come here" << std::endl;
        std::cout << NameSub << ": this part should not appear in the documentation" << std::endl;

        // Assuming some operations on the parameters and a local variable
        float AnImportantLocalVariable = InputVar * ExampleParameter; // Example operation
        OutputVar = AnImportantLocalVariable * 2.0f;
        InputOutputVar *= 3.0f; // Modify InputOutputVar to show it's input-output
    }

} // namespace ModExample2

// Example usage and test
int main() {
    float inputVar = 10.0f;
    float outputVar = 0.0f; // Initialized to 0 for clarity
    float inputOutputVar = 5.0f;

    ModExample2::example_iroutine(inputVar, outputVar, inputOutputVar);

    std::cout << "After example_iroutine:" << std::endl;
    std::cout << "OutputVar: " << outputVar << std::endl; // Expected: 20.0
    std::cout << "InputOutputVar: " << inputOutputVar << std::endl; // Expected: 15.0

    return 0;
}