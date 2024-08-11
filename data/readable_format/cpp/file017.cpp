#include <iostream>
using namespace std;

// Mocking the external C functions
extern "C" {
    int h5zunregister_c(int filter) { return 0; } // Mock success
    int h5zfilter_avail_c(int filter, int& flag) { flag = 1; return 0; } // Mock available
    int h5zget_filter_info_c(int filter, unsigned& config_flags) { config_flags = 2; return 0; } // Mock flags
}

namespace H5Z {

void h5zunregister(int filter, int& hdferr) {
    hdferr = h5zunregister_c(filter);
}

void h5zfilter_avail(int filter, bool& status, int& hdferr) {
    int flag = 0;
    hdferr = h5zfilter_avail_c(filter, flag);
    status = flag != 0;
}

void h5zget_filter_info(int filter, unsigned& config_flags, int& hdferr) {
    hdferr = h5zget_filter_info_c(filter, config_flags);
}

} // namespace H5Z

int main() {
    int hdferr = 0;
    bool status = false;
    unsigned config_flags = 0;
    int filter = 1;

    H5Z::h5zunregister(filter, hdferr);
    cout << "h5zunregister Error Code: " << hdferr << endl;

    H5Z::h5zfilter_avail(filter, status, hdferr);
    cout << "h5zfilter_avail Status: " << boolalpha << status << ", Error Code: " << hdferr << endl;

    H5Z::h5zget_filter_info(filter, config_flags, hdferr);
    cout << "h5zget_filter_info Config Flags: " << config_flags << ", Error Code: " << hdferr << endl;

    return 0;
}