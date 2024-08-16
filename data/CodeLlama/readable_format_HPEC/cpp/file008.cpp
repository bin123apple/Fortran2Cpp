#include <omp.h>

// Assuming global_foo is a namespace or class with a static method foo()
namespace global_foo {
    void foo() {
        // Implementation of foo()
    }
}

int main() {
    #pragma omp parallel
    {
        global_foo::foo();
    }
    return 0;
}
