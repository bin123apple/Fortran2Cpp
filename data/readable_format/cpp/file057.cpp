#include <iostream>
#include <vector>

// Define the noseHoover class directly in this file
class noseHoover {
public:
    int nnos;
    float kT, gkT, gT;
    std::vector<float> xi;
    std::vector<float> v_xi;
    std::vector<float> Q_i;
    std::vector<float> G_i;
    std::vector<float> omega;
    bool debug;

    // Constructors, destructors, and other member functions can be added here
};

int main() {
    noseHoover nh;

    nh.nnos = 5;
    nh.kT = 1.0f;
    nh.gkT = 2.0f;
    nh.gT = 3.0f;
    nh.debug = true;

    nh.xi.resize(nh.nnos, 1.0f);
    nh.v_xi.resize(nh.nnos, 2.0f);
    nh.Q_i.resize(nh.nnos, 3.0f);
    nh.G_i.resize(nh.nnos, 4.0f);
    nh.omega.resize(nh.nnos, 5.0f);

    std::cout << "nnos = " << nh.nnos << std::endl;
    std::cout << "kT = " << nh.kT << std::endl;
    std::cout << "gkT = " << nh.gkT << std::endl;
    std::cout << "gT = " << nh.gT << std::endl;
    std::cout << "xi[0] = " << nh.xi[0] << std::endl;
    std::cout << "v_xi[0] = " << nh.v_xi[0] << std::endl;
    std::cout << "Q_i[0] = " << nh.Q_i[0] << std::endl;
    std::cout << "G_i[0] = " << nh.G_i[0] << std::endl;
    std::cout << "omega[0] = " << nh.omega[0] << std::endl;
    std::cout << "debug = " << nh.debug << std::endl;

    return 0;
}