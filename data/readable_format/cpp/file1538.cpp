#include <iostream>
#include <random>
#include <vector>
#include <cmath>

class ProbabilityDistributions {
public:
    ProbabilityDistributions() {
        // Initialize the random seed
        rand_engine.seed(std::random_device{}());
    }

    double generateNormalRatioOfUniforms() {
        // Placeholder for the method's implementation
        std::normal_distribution<double> distribution(0.0, 1.0);
        return distribution(rand_engine);
    }

    std::vector<double> generateNDimNormalRatioOfUniforms(int N) {
        std::vector<double> result(N);
        for (int i = 0; i < N; ++i) {
            result[i] = generateNormalRatioOfUniforms();
        }
        return result;
    }

    double generateNormalBoxMuller() {
        double u1 = uniform_distribution(rand_engine);
        double u2 = uniform_distribution(rand_engine);
        double R = sqrt(-2.0 * log(u1));
        double theta = 2.0 * M_PI * u2;
        return R * cos(theta); // Or R * sin(theta) for the second number
    }

private:
    std::mt19937 rand_engine; // Mersenne Twister random number engine
    std::uniform_real_distribution<double> uniform_distribution{0.0, 1.0};
};

int main() {
    ProbabilityDistributions pd;

    std::cout << "A normally distributed number (Ratio of Uniforms): " << pd.generateNormalRatioOfUniforms() << std::endl;

    auto nDimNumbers = pd.generateNDimNormalRatioOfUniforms(5);
    std::cout << "A 5-dimensional array of normally distributed numbers (Ratio of Uniforms): ";
    for (double num : nDimNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "A normally distributed number (Box-Muller): " << pd.generateNormalBoxMuller() << std::endl;

    // Simple assertion tests
    double testNumber = pd.generateNormalBoxMuller();
    if (testNumber >= -5.0 && testNumber <= 5.0) {
        std::cout << "Box-Muller test passed." << std::endl;
    } else {
        std::cout << "Box-Muller test failed." << std::endl;
    }

    return 0;
}