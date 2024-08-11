#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <stdexcept>

// Assuming s2_sp as float and s2_spc as std::complex<float> for the sake of example
using s2_sp = float;
using s2_spc = std::complex<float>;

namespace comb_tmplalm_mod {

// Mimic the error codes and function, assuming COMB_ERROR_TMPL_PARAM_INVALID is an int constant
const int COMB_ERROR_TMPL_PARAM_INVALID = 1;

void comb_error(int error_code, const std::string& function_name) {
    // Basic error handling example. In a real scenario, it'd be more elaborate.
    throw std::runtime_error("Error in " + function_name + ": Invalid parameter size.");
}

class CombTmplalm {
public:
    static s2_spc comb_tmplalm_gaussian(int el, int m, const std::vector<s2_sp>& param = {}) {
        s2_sp sigma = 0.05e0;
        // Check for optional parameter
        if (!param.empty()) {
            if (param.size() != 1) {
                comb_error(COMB_ERROR_TMPL_PARAM_INVALID, "comb_tmplalm_gaussian");
            }
            sigma = param[0];
        }

        if (m == 0) {
            return std::exp(-el * el * sigma * sigma / 2);
        } else {
            return {0, 0}; // Return 0 for non-zero m values
        }
    }
};

} // namespace comb_tmplalm_mod

// Main program to demonstrate usage
int main() {
    using namespace comb_tmplalm_mod;
    try {
        auto result = CombTmplalm::comb_tmplalm_gaussian(2, 0);
        std::cout << "Result (m=0, no param): " << result << std::endl;
        
        std::vector<s2_sp> param = {0.1f};
        result = CombTmplalm::comb_tmplalm_gaussian(2, 0, param);
        std::cout << "Result (m=0, with param): " << result << std::endl;
        
        // This call is expected to throw an error due to invalid parameter size
        try {
            param = {0.1f, 0.2f}; // Invalid parameter size
            result = CombTmplalm::comb_tmplalm_gaussian(2, 0, param);
        } catch (const std::exception& e) {
            std::cerr << "Expected error: " << e.what() << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}