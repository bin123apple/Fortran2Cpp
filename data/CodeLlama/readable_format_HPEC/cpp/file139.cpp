#include <iostream>
#include <omp.h>

// Define the pair structure
struct pair {
    int a;
    int b;
    omp_nest_lock_t lck;
};

// Function prototypes
void incr_a(pair& p, int& a);
void incr_b(pair& p, int& b);

int main() {
    int a, b;
    pair p;
    p.a = 0;
    p.b = 0;

    // Initialize the nest lock
    omp_init_nest_lock(&p.lck);

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            omp_set_nest_lock(&p.lck);
            incr_b(p, a);
            incr_a(p, b);
            omp_unset_nest_lock(&p.lck);
        }

        #pragma omp section
        {
            incr_b(p, b);
        }
    }

    // Destroy the nest lock
    omp_destroy_nest_lock(&p.lck);

    std::cout << p.b << std::endl;

    return 0;
}

// Function definitions
void incr_a(pair& p, int& a) {
    omp_set_lock(&p.lck);
    p.a += 1;
    a = p.a;
    omp_unset_lock(&p.lck);
}

void incr_b(pair& p, int& b) {
    omp_set_lock(&p.lck);
    p.b += 1;
    b = p.b;
    omp_unset_lock(&p.lck);
}
