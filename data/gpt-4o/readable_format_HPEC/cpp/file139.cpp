#include <stdio.h>
#include <omp.h>

struct pair {
    int a;
    int b;
    omp_nest_lock_t lck;
};

void incr_a(pair &p, int &b) {
    // Function body goes here
}

void incr_b(pair &p, int &a) {
    // Function body goes here
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
            omp_set_nest_lock(&p.lck);
            incr_b(p, p.a);
            incr_a(p, p.b);
            omp_unset_nest_lock(&p.lck);
        }
#pragma omp section
        {
            incr_b(p, p.b);
        }
    }

    omp_destroy_nest_lock(&p.lck);

    printf("%d\n", p.b);

    return 0;
}
