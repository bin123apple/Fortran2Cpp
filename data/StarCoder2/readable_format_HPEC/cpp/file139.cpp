#include <iostream>
#include <omp.h>

// Define a struct to mimic the Fortran type 'pair'
struct Pair {
    int a;
    int b;
    omp_nest_lock_t lck; // OpenMP nest lock

    Pair() : a(0), b(0) {
        omp_init_nest_lock(&lck); // Initialize the nest lock
    }

    ~Pair() {
        omp_destroy_nest_lock(&lck); // Destroy the nest lock
    }
};

// Function to increment 'b'
void incr_b(Pair& p, int& b) {
    b += 1;
}

// Function to increment 'a'
void incr_a(Pair& p, int& a) {
    omp_set_nest_lock(&p.lck); // Set the nest lock
    a += 1;
    omp_unset_nest_lock(&p.lck); // Unset the nest lock
}

int main() {
    Pair p;
    int a = 0;
    int b = 0;

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            incr_a(p, a);
            incr_b(p, a); // This will not affect 'b' due to the lock
        }

        #pragma omp section
        {
            incr_b(p, b);
        }
    }

    std::cout << p.b << std::endl;

    return 0;
}
