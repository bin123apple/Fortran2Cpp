#include <iostream>
#include <random>
#include <vector>
#include <cmath>
#include <chrono>
#include <algorithm>
#include <numeric>
#include <functional>

class Random {
public:
    Random() {
        init_random_seed();
    }

    void init_random_seed() {
        std::random_device rd;
        engine.seed(rd());
    }

    void set_random_seed(unsigned int seed_offset) {
        engine.seed(seed_offset);
    }

    double rand_uniform() {
        std::uniform_real_distribution<> dist(0.0, 1.0);
        return dist(engine);
    }

    int rand_int(int lo, int up) {
        std::uniform_int_distribution<> dist(lo, up);
        return dist(engine);
    }

    std::vector<double> rand_vec(int n) {
        std::vector<double> vec(n);
        std::generate(vec.begin(), vec.end(), [this]() { return rand_uniform(); });
        return vec;
    }

    double randc(double x0, double gamma) {
        double u = rand_uniform();
        return std::tan((u - 0.5) * M_PI) * gamma + x0;
    }

    double randn(double mean, double std) {
        std::normal_distribution<> dist(mean, std);
        return dist(engine);
    }

    std::vector<double> randn_vec(int n) {
        std::vector<double> vec(n);
        std::generate(vec.begin(), vec.end(), [this]() { return randn(0.0, 1.0); });
        return vec;
    }

private:
    std::default_random_engine engine;
};

int main() {
    Random rng;

    // Example usage
    std::cout << "Uniform random number: " << rng.rand_uniform() << std::endl;
    std::cout << "Random integer between 1 and 10: " << rng.rand_int(1, 10) << std::endl;
    std::cout << "Normally distributed random number (mean=0, std=1): " << rng.randn(0.0, 1.0) << std::endl;

    auto vec = rng.rand_vec(5);
    std::cout << "Random vector: ";
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}