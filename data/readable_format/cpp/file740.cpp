#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

std::mutex coutMutex;

void performTask(int thread_id) {
    int nerr = (thread_id == 0) ? 0 : 1; // Simulate no error for the first thread, error for others

    {
        std::lock_guard<std::mutex> guard(coutMutex);
        if (nerr == 0) {
            std::cout << "Process " << thread_id << ": OK" << std::endl;
        } else {
            std::cout << "Process " << thread_id << ": Error detected" << std::endl;
        }
    }
}

int main() {
    const int num_threads = 4; // Number of threads to simulate
    std::vector<std::thread> threads;

    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(performTask, i);
    }

    for (auto& t : threads) {
        t.join();
    }

    return 0;
}