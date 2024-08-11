#include <iostream>
#include <chrono>
#include <thread>

class Clock {
public:
    Clock() : elapsed_time(0.0) {}

    void start() {
        start_time = std::chrono::high_resolution_clock::now();
    }

    void stop() {
        auto stop_time = std::chrono::high_resolution_clock::now();
        elapsed_time = std::chrono::duration<double>(stop_time - start_time).count();
    }

    double getElapsedTime() const {
        return elapsed_time;
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
    double elapsed_time;
};

int main() {
    Clock clock;

    std::cout << "Starting clock..." << std::endl;
    clock.start();

    // Simulating work by sleeping for 1 second
    std::this_thread::sleep_for(std::chrono::seconds(1));

    clock.stop();
    std::cout << "Stopping clock..." << std::endl;

    std::cout << "Elapsed time: " << clock.getElapsedTime() << " seconds" << std::endl;

    // Simple assertion test
    if (clock.getElapsedTime() >= 1.0 && clock.getElapsedTime() < 1.1) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }

    return 0;
}