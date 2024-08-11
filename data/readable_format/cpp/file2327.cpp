#include <iostream>
#include <vector>
#include <string>
#include <array>

// Mock definition of Parameters
const int MX_NM = 100;
const float SRK = 1e-6; // Example value, adjust based on actual kind definition

// Mock definition of Rods
struct Rod {
    // Add properties of Rod here
};

// Mock definition of Reflectors
struct Reflector {
    // Add properties of Reflector here
};

namespace Cores {

class Core {
public:
    // Member variables
    std::string name;
    std::string geom;
    std::array<std::string, 3> bc;
    std::vector<std::vector<Rod>> grid;
    std::vector<Reflector> refs;
    float pwr;
    std::array<float, 2> pitch;

    // Constructor
    Core() = default;
    
    // Methods
    void init(const std::string& name, const std::string& geom, const std::array<int, 2>& dimen, const std::array<float, 2>& pitch, const std::array<std::string, 3>& bc) {
        this->name = name;
        this->geom = geom;
        this->pitch = pitch;
        this->bc = bc;
        this->grid.resize(dimen[0], std::vector<Rod>(dimen[1]));
        // You can add initialization for grid elements and refs here if needed
    }

    void clear() {
        grid.clear();
        refs.clear();
    }

    // Destructor
    ~Core() {
        clear();
    }
};

} // namespace Cores

int main() {
    using namespace Cores;

    Core core;
    std::string name = "TestCore";
    std::string geom = "Geometry";
    std::array<int, 2> dimen = {10, 10};
    std::array<float, 2> pitch = {1.0f, 1.5f};
    std::array<std::string, 3> bc = {"BC1", "BC2", "BC3"};

    // Initialize the core
    core.init(name, geom, dimen, pitch, bc);

    // Print to verify
    std::cout << "Core name: " << core.name << std::endl;
    std::cout << "Core geometry: " << core.geom << std::endl;
    std::cout << "Core boundary conditions: ";
    for (const auto& condition : core.bc) {
        std::cout << condition << " ";
    }
    std::cout << std::endl;
    std::cout << "Core pitch: " << core.pitch[0] << ", " << core.pitch[1] << std::endl;

    // Clear the core
    core.clear();

    std::cout << "Core cleared successfully." << std::endl;

    return 0;
}