#include <iostream>
#include <openacc.h>
#include <cstdlib>

int main() {
    int num_devices = acc_get_num_devices(acc_device_nvidia);

    // Test if NVIDIA devices are available
    if (num_devices == 0) {
        std::cout << "No NVIDIA devices available - Test Failed" << std::endl;
        return EXIT_FAILURE;
    } else {
        std::cout << "NVIDIA devices available - Test Passed" << std::endl;
    }

    // Initialize and set device, then check device number
    acc_init(acc_device_nvidia);
    acc_set_device_num(0, acc_device_nvidia);
    int device_num = acc_get_device_num(acc_device_nvidia);

    if (device_num == 0) {
        std::cout << "Device set correctly to 0 - Test Passed" << std::endl;
    } else {
        std::cout << "Device not set correctly - Test Failed" << std::endl;
        std::abort();
    }

    // Shutdown and final test for multiple devices
    acc_shutdown(acc_device_nvidia);
    if (num_devices > 1) {
        std::cout << "Multiple NVIDIA devices available - Test Consideration" << std::endl;
    } else {
        std::cout << "Single NVIDIA device available - Test Consideration" << std::endl;
    }

    return EXIT_SUCCESS;
}