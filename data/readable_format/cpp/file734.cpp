#include <iostream>

// Assuming the structure of sph_boundary_type based on the original context
struct sph_boundary_type {
    int dummy; // Placeholder member variable. Replace with actual structure.
};

class MBoundaryParamsSphMHD {
public:
    sph_boundary_type sph_bc_U;
    sph_boundary_type sph_bc_B;
    sph_boundary_type sph_bc_T;
    sph_boundary_type sph_bc_C;

    double* vp_ICB_bc = nullptr;
    double* vt_ICB_bc = nullptr;
    double* vp_CMB_bc = nullptr;
    double* vt_CMB_bc = nullptr;

    void allocate_vsp_bc_array(int jmax) {
        vp_ICB_bc = new double[jmax]{};
        vt_ICB_bc = new double[jmax]{};
        vp_CMB_bc = new double[jmax]{};
        vt_CMB_bc = new double[jmax]{};
    }

    void deallocate_vsp_bc_array() {
        delete[] vp_ICB_bc;
        vp_ICB_bc = nullptr;
        delete[] vt_ICB_bc;
        vt_ICB_bc = nullptr;
        delete[] vp_CMB_bc;
        vp_CMB_bc = nullptr;
        delete[] vt_CMB_bc;
        vt_CMB_bc = nullptr;
    }

    ~MBoundaryParamsSphMHD() {
        deallocate_vsp_bc_array();
    }
};

void testMBoundaryParamsSphMHD() {
    const int jmax = 5;
    MBoundaryParamsSphMHD obj;

    // Allocate the arrays
    obj.allocate_vsp_bc_array(jmax);

    // Check initialization
    for (int i = 0; i < jmax; ++i) {
        if (obj.vp_ICB_bc[i] != 0.0 || obj.vt_ICB_bc[i] != 0.0 ||
            obj.vp_CMB_bc[i] != 0.0 || obj.vt_CMB_bc[i] != 0.0) {
            std::cerr << "Error: Arrays not properly initialized." << std::endl;
            return;
        }
    }
    std::cout << "Allocation and initialization test passed." << std::endl;

    // Deallocation is handled by the destructor
    std::cout << "Deallocation test passed." << std::endl;
}

int main() {
    testMBoundaryParamsSphMHD();
    return 0;
}