#include <stdexcept> // Include for std::runtime_error

void foo() {
    throw std::runtime_error("failed");
}