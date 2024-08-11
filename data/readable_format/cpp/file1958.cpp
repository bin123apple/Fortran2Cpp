#include <iostream>
#include <memory>

// Combining the namespace and structs into one file
namespace automatic_deallocation {

struct t0 {
    int i;
};

struct t1 {
    float pi = 3.14;
    std::unique_ptr<int> j; // Using smart pointers for automatic memory management
};

struct t2 {
    std::unique_ptr<t0> k;
};

void a() {
    std::unique_ptr<int> m(new int); // Dynamic memory allocation
    *m = 42;
    std::cout << "Subroutine a: m allocated and set to " << *m << std::endl;
}

void b() {
    std::unique_ptr<t0> m(new t0); // Dynamic memory allocation with the type t0
    m->i = 43;
    std::cout << "Subroutine b: m->i allocated and set to " << m->i << std::endl;
}

void c() {
    t1 m; // Automatic storage, as t1 has a default constructor
    m.j = std::make_unique<int>(44); // Direct allocation and assignment
    std::cout << "Subroutine c: m.j allocated and set to " << *m.j << std::endl;
}

void d() {
    t2 m; // Automatic storage
    m.k = std::make_unique<t0>(); // Allocation of t0 for the member k
    m.k->i = 45;
    std::cout << "Subroutine d: m.k->i allocated and set to " << m.k->i << std::endl;
}

} // namespace automatic_deallocation

// Main function demonstrating the use of the above definitions
int main() {
    automatic_deallocation::a();
    automatic_deallocation::b();
    automatic_deallocation::c();
    automatic_deallocation::d();

    return 0;
}