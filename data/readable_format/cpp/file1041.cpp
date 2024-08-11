#include <iostream>
#include <array>
#include <cassert>

namespace tensors_rk {

using dp = double; // Assuming dp represents double precision

struct tensor_rank0 {
    dp sca;
};

struct tensor_rank1 {
    std::array<dp, 3> a;
    std::array<dp, 3> a_damp;
    std::array<dp, 3> a_damp2;
};

struct tensor_rank2 {
    std::array<std::array<dp, 3>, 3> ab;
    std::array<std::array<dp, 3>, 3> ab_damp;
    std::array<std::array<dp, 3>, 3> ab_damp2;
    std::array<std::array<dp, 3>, 3> ab_thole;
};

struct tensor_rank3 {
    std::array<std::array<std::array<dp, 3>, 3>, 3> abc;
};

struct tensor_rank4 {
    std::array<std::array<std::array<std::array<dp, 3>, 3>, 3>, 3> abcd;
};

struct tensor_rank5 {
    std::array<std::array<std::array<std::array<std::array<dp, 3>, 3>, 3>, 3>, 3> abcde;
};

struct interaction_dd {
    tensor_rank2 T2;
    tensor_rank3 T3;
};

} // namespace tensors_rk

int main() {
    using namespace tensors_rk;

    // Test tensor_rank0
    tensor_rank0 t0;
    t0.sca = 1.0;
    assert(t0.sca == 1.0);
    std::cout << "tensor_rank0 sca = " << t0.sca << std::endl;

    // Test tensor_rank1
    tensor_rank1 t1;
    t1.a = {1.0, 2.0, 3.0};
    assert(t1.a[0] == 1.0 && t1.a[1] == 2.0 && t1.a[2] == 3.0);
    std::cout << "tensor_rank1 a[0] = " << t1.a[0] << std::endl;

    // Test tensor_rank2
    tensor_rank2 t2;
    t2.ab[0][0] = 1.0;
    assert(t2.ab[0][0] == 1.0);
    std::cout << "tensor_rank2 ab[0][0] = " << t2.ab[0][0] << std::endl;

    // Test tensor_rank3
    tensor_rank3 t3;
    t3.abc[0][0][0] = 1.0;
    assert(t3.abc[0][0][0] == 1.0);
    std::cout << "tensor_rank3 abc[0][0][0] = " << t3.abc[0][0][0] << std::endl;

    // Test tensor_rank4
    tensor_rank4 t4;
    t4.abcd[0][0][0][0] = 1.0;
    assert(t4.abcd[0][0][0][0] == 1.0);
    std::cout << "tensor_rank4 abcd[0][0][0][0] = " << t4.abcd[0][0][0][0] << std::endl;

    // Test tensor_rank5
    tensor_rank5 t5;
    t5.abcde[0][0][0][0][0] = 1.0;
    assert(t5.abcde[0][0][0][0][0] == 1.0);
    std::cout << "tensor_rank5 abcde[0][0][0][0][0] = " << t5.abcde[0][0][0][0][0] << std::endl;

    // Test interaction_dd
    interaction_dd int_dd;
    int_dd.T2.ab[0][0] = 2.0;
    assert(int_dd.T2.ab[0][0] == 2.0);
    std::cout << "interaction_dd T2 ab[0][0] = " << int_dd.T2.ab[0][0] << std::endl;

    std::cout << "All tests passed." << std::endl;
    return 0;
}