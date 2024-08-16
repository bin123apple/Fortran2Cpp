#include <iostream>
#include <omp.h>

struct pair {
    int a;
    int b;
    omp_nest_lock_t lck;
};

void incr_a(pair& p, int& a) {
    omp_set_nest_lock(&p.lck);
    p.a += 1;
    a = p.a;
    omp_unset_nest_lock(&p.lck);
}

void incr_b(pair& p, int& b) {
    omp_set_nest_lock(&p.lck);
    p.b += 1;
    b = p.b;
    omp_unset_nest_lock(&p.lck);
}

int main() {
    pair p;
    p.a = 0;
    p.b = 0;
    omp_init_nest_lock(&p.lck);

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            incr_b(p, p.b);
        }
        #pragma omp section
        {
            int a;
            incr_a(p, a);
        }
    }

    omp_destroy_nest_lock(&p.lck);

    std::cout << p.b << std::endl;

    return 0;
}
