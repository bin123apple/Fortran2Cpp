#include <atomic>
#include <cstdint>
#include <iostream>

int main() {
    std::atomic<int32_t> a; // Assuming atomic_int_kind is equivalent to int32_t
    std::atomic<bool> c;
    int64_t b; // Equivalent to integer(8)
    bool d; // Equivalent to logical(1)

    // atomic_define(a(1), 7_2)
    a.store(7);

    // atomic_ref(b, a(1))
    b = a.load();
    if (b != a.load()) {
        std::cerr << "Mismatch in atomic integer values, stopping." << std::endl;
        return 1;
    }

    // atomic_define(c, .false.)
    c.store(false);

    // atomic_ref(d, c[this_image()])
    d = c.load();
    if (d != false) {
        std::cerr << "Expected false, stopping." << std::endl;
        return 2;
    }

    // atomic_define(c[this_image()], .true.)
    c.store(true);

    // atomic_ref(d, c)
    d = c.load();
    if (d != true) {
        std::cerr << "Expected true, stopping." << std::endl;
        return 3;
    }

    return 0;
}