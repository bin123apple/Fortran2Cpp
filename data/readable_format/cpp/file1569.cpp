#include <iostream>
#include <vector>
#include <string>
#include <array>

// Merging the globals.hpp content directly into this file
namespace globals {
    int rank;

    int nbmin;
    int nbmax;
    int nbrootx;
    int nbrooty;
    int nbrootz;
    int maxcells_x;
    int maxcells_y;
    int maxcells_z;
    int maxlev;
    int nbLocal;
    int nbActive;

    int it;
    float time;
    float dt;
    int nextout;

    int start_mark;
    int logu;
    std::string logfile;
    std::string host;

    std::vector<std::vector<std::vector<std::vector<std::vector<float>>>>> U;
    std::vector<std::vector<std::vector<std::vector<std::vector<float>>>>> UP;
    std::vector<std::vector<std::vector<std::vector<std::vector<float>>>>> PRIM;

    std::vector<std::vector<std::vector<std::vector<float>>>> F;
    std::vector<std::vector<std::vector<std::vector<float>>>> G;
    std::vector<std::vector<std::vector<std::vector<float>>>> H;
    std::vector<std::vector<std::vector<std::vector<float>>>> FC;
    std::vector<std::vector<std::vector<std::vector<float>>>> GC;
    std::vector<std::vector<std::vector<std::vector<float>>>> HC;

    std::vector<int> globalBlocks;
    std::vector<int> refineFlags;
    std::vector<int> localBlocks;
    std::vector<int> nblockslev;
    std::vector<int> nbx;
    std::vector<int> nby;
    std::vector<int> nbz;
    std::vector<int> minID;
    std::vector<int> maxID;
    std::vector<float> dx;
    std::vector<float> dy;
    std::vector<float> dz;

    std::vector<std::vector<float>> cooltable;
    int nptsT;
    int nptsZ;
    float cool_Tmin;
    float cool_Tmax;
    float cool_Zmin;
    float cool_Zmax;

    std::array<float, 3> timings;
}

// Test program
int main() {
    // Example of setting some values
    globals::rank = 1;
    globals::nbmin = 10;
    globals::nbmax = 20;

    // Print to verify
    std::cout << "Testing C++ globals namespace" << std::endl;
    std::cout << "rank: " << globals::rank << std::endl;
    std::cout << "nbmin: " << globals::nbmin << std::endl;
    std::cout << "nbmax: " << globals::nbmax << std::endl;
    
    // You can expand this test as needed
    return 0;
}