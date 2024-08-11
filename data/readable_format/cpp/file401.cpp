#include <iostream>
#include <cstring>

class Constants {
public:
    static constexpr bool BIN_OUTPUT = false;
    static constexpr int FFT_TYPE = 1;
    static constexpr int CUSTOM_REAL = 8;
    static constexpr char SRC_PATH[] = "your_src_path_here";
    static constexpr double PI = 3.141592653589793;
    static constexpr double DAY = 3600.0*24.0;
    static constexpr double WEEK = 7.0*DAY;
    static constexpr double MONTH = 30*DAY;
    static constexpr double YEAR = 365*DAY;
    static constexpr int FID_IN = 15;
    static constexpr int FID_SCREEN = 6;
    static constexpr int FID_OT = 18;
    static constexpr int FID_OX = 19;
    static constexpr int FID_VMAX = 22;
    static constexpr int FID_IASP = 23;
    static constexpr int FID_QSB_PRE = 100;
    static constexpr int FID_QSB_POST = 101;
    static constexpr int FID_TIME = 121;
    static constexpr int FID_STATIONS = 200;
    static constexpr int FID_MW = 222;
    static constexpr int FID_OX_DYN = 20000;
    static constexpr char FILE_OX[] = "output_ox";
    static constexpr char FILE_OX_DYN_PRE[] = "output_dyn_pre_";
    static constexpr char FILE_OX_DYN_POST[] = "output_dyn_post_";
    static constexpr char FILE_OX_DYN_MAX[] = "output_dyn_max_";
    static constexpr char FILE_OT[] = "output_ot_";
    static constexpr char FILE_IASP[] = "output_iasp";
    static constexpr char FILE_VMAX[] = "output_vmax";
    
    static int FAULT_TYPE;
    static int SOLVER_TYPE;
};

int Constants::FAULT_TYPE = 0;
int Constants::SOLVER_TYPE = 0;

int main() {
    if (!Constants::BIN_OUTPUT) std::cout << "BIN_OUTPUT Test Passed" << std::endl; 
    else std::cout << "BIN_OUTPUT Test Failed" << std::endl;

    if (Constants::FFT_TYPE == 1) std::cout << "FFT_TYPE Test Passed" << std::endl; 
    else std::cout << "FFT_TYPE Test Failed" << std::endl;

    // Continue with other tests...

    Constants::FAULT_TYPE = 1;
    if (Constants::FAULT_TYPE == 1) std::cout << "FAULT_TYPE Test Passed" << std::endl; 
    else std::cout << "FAULT_TYPE Test Failed" << std::endl;

    // Reset the variable to avoid side-effects for other potential tests
    Constants::FAULT_TYPE = 0;

    // Continue with other tests as needed...

    return 0;
}