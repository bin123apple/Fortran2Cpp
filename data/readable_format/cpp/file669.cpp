#include <cstdint>

extern "C" {
    // Translated from subroutine sub1 and its entry sub1_c
    void sub1(int32_t x) {
        // Original subroutine body would go here
    }

    void sub1_c(int32_t x) {
        sub1(x); // Calls the same internal logic as sub1
    }

    // Translated from subroutine sub2_c and its entry sub2
    void sub2_c(int32_t x) {
        // Original subroutine body would go here
    }

    void sub2(int32_t x) {
        sub2_c(x); // Calls the same internal logic as sub2_c
    }

    // Translated from subroutine sub3_c and its entry sub3_c_c
    void sub3_c(int32_t x) {
        // Original subroutine body would go here
    }

    void sub3_c_c(int32_t x) {
        sub3_c(x); // Calls the same internal logic as sub3_c
    }
}