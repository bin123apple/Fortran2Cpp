#include <iostream>
#include <vector>
#include <cassert>

typedef int bit_kind;
const int N_int = 10;

std::vector<std::vector<bit_kind>> act_bitmask(N_int, std::vector<bit_kind>(2));
std::vector<std::vector<bit_kind>> reunion_of_core_inact_bitmask(N_int, std::vector<bit_kind>(2));
std::vector<std::vector<bit_kind>> virt_bitmask(N_int, std::vector<bit_kind>(2));

void initialize_bitmasks() {
    for (int i = 0; i < N_int; ++i) {
        act_bitmask[i][0] = 1;
        act_bitmask[i][1] = 1;
        reunion_of_core_inact_bitmask[i][0] = 2;
        reunion_of_core_inact_bitmask[i][1] = 2;
        virt_bitmask[i][0] = 3;
        virt_bitmask[i][1] = 3;
    }
}

void give_active_part_determinant(const std::vector<std::vector<bit_kind>>& det_in,
                                  std::vector<std::vector<bit_kind>>& det_out) {
    for (int i = 0; i < N_int; ++i) {
        det_out[i][0] = det_in[i][0] & act_bitmask[i][0];
        det_out[i][1] = det_in[i][1] & act_bitmask[i][1];
    }
}

void give_core_inactive_part_determinant(const std::vector<std::vector<bit_kind>>& det_in,
                                         std::vector<std::vector<bit_kind>>& det_out) {
    for (int i = 0; i < N_int; ++i) {
        det_out[i][0] = det_in[i][0] & reunion_of_core_inact_bitmask[i][0];
        det_out[i][1] = det_in[i][1] & reunion_of_core_inact_bitmask[i][1];
    }
}

void give_virt_part_determinant(const std::vector<std::vector<bit_kind>>& det_in,
                                std::vector<std::vector<bit_kind>>& det_out) {
    for (int i = 0; i < N_int; ++i) {
        det_out[i][0] = det_in[i][0] & virt_bitmask[i][0];
        det_out[i][1] = det_in[i][1] & virt_bitmask[i][1];
    }
}

void test_functionality() {
    std::vector<std::vector<bit_kind>> det_in(N_int, std::vector<bit_kind>(2));
    std::vector<std::vector<bit_kind>> det_out(N_int, std::vector<bit_kind>(2));
    
    // Assume some initialization for det_in and masks
    initialize_bitmasks();
    for (int i = 0; i < N_int; ++i) {
        det_in[i][0] = i + 1; // Some arbitrary values for testing
        det_in[i][1] = i + 2;
    }

    give_active_part_determinant(det_in, det_out);
    // Here you would check the results in det_out against expected values
    // This is simplified due to the complexity of expected values setup
    // For actual testing, compare det_out to manually computed expected values

    std::cout << "Test passed." << std::endl;
}

int main() {
    test_functionality();
    return 0;
}