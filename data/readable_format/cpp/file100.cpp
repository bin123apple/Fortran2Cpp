#include <iostream>
#include <vector>
#include <algorithm>
#include <omp.h>

class m_work_4_sph_trans_spin {
public:
    std::vector<double> vr_rtm_wk;
    std::vector<double> sp_rlm_wk;

    // Assuming nnod_rlm and nnod_rtm are simplified constants for this example
    const int nnod_rlm = 10;
    const int nnod_rtm = 20;

    void allocate_work_sph_trans(int ncomp) {
        sp_rlm_wk.resize(nnod_rlm * ncomp);
        vr_rtm_wk.resize(nnod_rtm * ncomp);

        clear_bwd_legendre_work(ncomp);
        clear_fwd_legendre_work(ncomp);
    }

    void deallocate_work_sph_trans() {
        vr_rtm_wk.clear();
        sp_rlm_wk.clear();
    }

    void clear_fwd_legendre_work(int ncomp) {
        if (ncomp <= 0) return;
        #pragma omp parallel for
        for (int i = 0; i < nnod_rlm * ncomp; ++i) {
            sp_rlm_wk[i] = 0.0;
        }
    }

    void clear_bwd_legendre_work(int ncomp) {
        if (ncomp <= 0) return;
        #pragma omp parallel for
        for (int i = 0; i < nnod_rtm * ncomp; ++i) {
            vr_rtm_wk[i] = 0.0;
        }
    }
};

void test_work_4_sph_trans_spin() {
    m_work_4_sph_trans_spin work;
    const int test_ncomp = 5;

    work.allocate_work_sph_trans(test_ncomp);
    std::cout << "Allocated work arrays." << std::endl;

    if (!work.sp_rlm_wk.empty() && !work.vr_rtm_wk.empty()) {
        std::cout << "Allocation test passed." << std::endl;
    } else {
        std::cout << "Allocation test failed." << std::endl;
    }

    std::fill(work.sp_rlm_wk.begin(), work.sp_rlm_wk.end(), 1.0); // Simulate usage
    work.clear_fwd_legendre_work(test_ncomp);
    if (std::all_of(work.sp_rlm_wk.begin(), work.sp_rlm_wk.end(), [](double val) { return val == 0.0; })) {
        std::cout << "Clear forward work passed." << std::endl;
    } else {
        std::cout << "Clear forward work failed." << std::endl;
    }

    work.deallocate_work_sph_trans();
    std::cout << "Deallocated work arrays." << std::endl;
}

int main() {
    test_work_4_sph_trans_spin();
    return 0;
}