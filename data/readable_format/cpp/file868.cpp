#include <cmath>
#include <chrono>
#include <random>
#include <iostream>

std::pair<double, double> boxMuller() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> dis(0.0, 1.0);

    double u1 = dis(gen);
    double u2 = dis(gen);
    double r = sqrt(-2.0 * log(u1));
    double theta = 2.0 * M_PI * u2;
    double x = r * cos(theta);
    double y = r * sin(theta);

    return std::make_pair(x, y);
}

int main() {
    const int Nsim = 10000;
    double mean = 0.0, variance = 0.0;
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < Nsim; ++i) {
        auto nums = boxMuller();
        mean += nums.first + nums.second;
        variance += nums.first * nums.first + nums.second * nums.second;
    }

    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    
    mean /= (2*Nsim);
    variance /= (2*Nsim);
    variance -= mean * mean;

    std::cout << "Mean: " << mean << std::endl;
    std::cout << "Variance: " << variance << std::endl;
    std::cout << "Elapsed Time: " << elapsed.count() << " seconds" << std::endl;

    return 0;
}