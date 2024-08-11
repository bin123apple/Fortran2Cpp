#include <iostream>
#include <vector>

// Define the DawritI class directly in this file
class DawritI {
public:
    static void dawrit(const std::vector<double>& V, int LEN, int NREC);
};

// Implement the dawrit function within the class definition
void DawritI::dawrit(const std::vector<double>& V, int LEN, int NREC) {
    double sum = 0.0;
    for (int i = 0; i < LEN; ++i) {
        sum += V[i];
    }
    std::cout << "Sum = " << sum << std::endl;
}

// The main function to demonstrate usage
int main() {
    std::vector<double> arr = {1.0, 2.0, 3.0, 4.0, 5.0};
    DawritI::dawrit(arr, arr.size(), 1);
    return 0;
}