#include <iostream>
#include <vector>

// Simulate the parallel functionality in a single-threaded context.
class SimulatedParallelArray {
public:
    std::vector<int64_t> a;
    std::vector<int> b;
    int me; // Simulated process ID

    SimulatedParallelArray(int processID) : me(processID) {
        a.resize(7, 0);
        b.resize(30, -1234); // 10 rows, 3 columns, but flattened
    }

    void run() {
        // Simulate setting 'a' based on 'me'
        for (int i = 0; i < 7; ++i) {
            a[i] = (i + 1) * (me + 1);
        }

        // Simulate communication and setting 'b'
        if (me == 1) {
            for (int i = 0; i < 7; ++i) {
                b[i * 3] = a[i];
            }
        }

        int nerr = 0;
        for (int j = 0; j < 3; ++j) {
            for (int i = 0; i < 10; ++i) {
                int nval = -1234;
                if (me == 1 && j == 0 && i < 7) {
                    nval = (i + 1) * 2;
                }

                if (nval != b[i * 3 + j]) {
                    std::cout << "b(" << i + 1 << "," << j + 1 << ")[" << me + 1
                              << "]=" << b[i * 3 + j] << " should be " << nval << std::endl;
                    nerr++;
                }
            }
        }

        if (nerr == 0) {
            std::cout << "result[" << me + 1 << "] OK" << std::endl;
        } else {
            std::cout << "result[" << me + 1 << "] number of NGs: " << nerr << std::endl;
        }
    }
};

int main() {
    SimulatedParallelArray process0(0);
    SimulatedParallelArray process1(1);

    // Simulate running both "processes" sequentially
    process0.run();
    process1.run();

    return 0;
}