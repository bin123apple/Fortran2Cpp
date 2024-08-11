#include <openacc.h>
#include <cstdlib> // For std::exit

int main() {
    int n;

    // Check if any NVIDIA GPU devices are available
    if (acc_get_num_devices(acc_device_nvidia) == 0) std::exit(EXIT_FAILURE);

    // Initialize OpenACC with the NVIDIA device
    acc_init(acc_device_nvidia);

    n = 0;

    // Set the active device to the first NVIDIA GPU
    acc_set_device_num(n, acc_device_nvidia);

    // Check if the active device is correctly set to 0
    if (acc_get_device_num(acc_device_nvidia) != 0) std::exit(1);

    // Check if there are more than one NVIDIA GPUs available
    if (acc_get_num_devices(acc_device_nvidia) > 1) {
        n = 1;

        // Set the active device to the second NVIDIA GPU
        acc_set_device_num(n, acc_device_nvidia);

        // Check if the active device is correctly set to 1
        if (acc_get_device_num(acc_device_nvidia) != 1) std::exit(2);
    }

    // Shutdown OpenACC for the NVIDIA device
    acc_shutdown(acc_device_nvidia);

    return 0;
}