#include <cstdint>  // for std::int64_t

struct TypeParamInt {
    std::int64_t i;
};

int main() {
    TypeParamInt t;
    t.i = 0;  // Example usage
    return 0;
}