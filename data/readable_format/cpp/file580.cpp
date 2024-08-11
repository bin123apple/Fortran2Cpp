#include <iostream>
#include <cmath> // For std::fabs

// Define the class directly in this file instead of using a separate header.
class ppm_module_data_loadbal {
public:
    // Assuming ppm_kind_double is equivalent to double
    using ppm_kind_double = double; 

    // Default constructor with initialization list
    ppm_module_data_loadbal()
        : ppm_loadbal_decomp_cost(0.0),
          ppm_loadbal_dcn(0),
          ppm_loadbal_runsum(0.0),
          ppm_loadbal_old_sar(-1.0) {}

    // Public getter functions
    ppm_kind_double get_decomp_cost() const { return ppm_loadbal_decomp_cost; }
    int get_dcn() const { return ppm_loadbal_dcn; }
    ppm_kind_double get_runsum() const { return ppm_loadbal_runsum; }
    ppm_kind_double get_old_sar() const { return ppm_loadbal_old_sar; }

    // Public setter functions
    void set_decomp_cost(ppm_kind_double value) { ppm_loadbal_decomp_cost = value; }
    void set_dcn(int value) { ppm_loadbal_dcn = value; }
    void set_runsum(ppm_kind_double value) { ppm_loadbal_runsum = value; }
    void set_old_sar(ppm_kind_double value) { ppm_loadbal_old_sar = value; }

private:
    ppm_kind_double ppm_loadbal_decomp_cost;
    int ppm_loadbal_dcn;
    ppm_kind_double ppm_loadbal_runsum;
    ppm_kind_double ppm_loadbal_old_sar;
};

// Simple test framework
void test(const std::string& test_name, bool test_result) {
    if (test_result) {
        std::cout << "Test passed: " << test_name << std::endl;
    } else {
        std::cout << "Test FAILED: " << test_name << std::endl;
    }
}

int main() {
    ppm_module_data_loadbal ppm_data;

    // Test initialization
    test("Initialization of ppm_loadbal_decomp_cost", ppm_data.get_decomp_cost() == 0.0);
    test("Initialization of ppm_loadbal_dcn", ppm_data.get_dcn() == 0);
    test("Initialization of ppm_loadbal_runsum", ppm_data.get_runsum() == 0.0);
    test("Initialization of ppm_loadbal_old_sar", ppm_data.get_old_sar() == -1.0);

    // Test modification and retrieval
    ppm_data.set_decomp_cost(10.0);
    ppm_data.set_dcn(5);
    ppm_data.set_runsum(20.0);
    ppm_data.set_old_sar(30.0);

    test("Modification and retrieval of ppm_loadbal_decomp_cost", std::fabs(ppm_data.get_decomp_cost() - 10.0) < 1e-6);
    test("Modification and retrieval of ppm_loadbal_dcn", ppm_data.get_dcn() == 5);
    test("Modification and retrieval of ppm_loadbal_runsum", std::fabs(ppm_data.get_runsum() - 20.0) < 1e-6);
    test("Modification and retrieval of ppm_loadbal_old_sar", std::fabs(ppm_data.get_old_sar() - 30.0) < 1e-6);

    return 0;
}