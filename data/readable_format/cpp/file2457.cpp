#include <iostream>
#include <thread>
#include <chrono>

class TimingModule {
public:
    double MPI_wtime() const {
        using namespace std::chrono;
        auto current_time = high_resolution_clock::now();
        auto time_since_epoch = current_time.time_since_epoch();
        double time_in_seconds = duration_cast<nanoseconds>(time_since_epoch).count() * 1e-9;
        return time_in_seconds;
    }
};

int main() {
    TimingModule timing;
    double start_time = timing.MPI_wtime();
    std::cout << "Start time: " << start_time << " seconds" << std::endl;

    // Perform some dummy work to introduce a delay
    std::this_thread::sleep_for(std::chrono::seconds(1));

    double end_time = timing.MPI_wtime();
    std::cout << "End time: " << end_time << " seconds" << std::endl;

    // Calculate and print the elapsed time
    std::cout << "Elapsed time: " << end_time - start_time << " seconds" << std::endl;

    return 0;
}