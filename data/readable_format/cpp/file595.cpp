#include <iostream>
#include <vector>

struct MYGA_PARAMS {
    // Static members to mimic Fortran module variables
    static int MYGA_NSTRUC, MYGA_NOFF;
    static int MYGA_NMUT;
    static int MYGA_GENS;
    static int MYGA_TOURN_SIZE;
    static bool MYGA_L_EPOCH;
    static int MYGA_EPOCH_SAVE;
    static bool MYGA_EPOCH_DUMP;
    static int MYGA_COUNT_EPOCH;
    static double MYGA_MUT_RATE;
    static int MYGA_CROSS;
    static double MYGA_BQMAX, MYGA_CQMAX;
    static double MYGA_DUPLICATE_ETHRESH;
    static double MYGA_DUPLICATE_GTHRESH;
    static double MYGA_EPOCH_THRESH;
    static double MYGA_LAST_ENERGY;
    static bool MYGA_L_ROUL;
    static bool MYGA_L_CHAIN;
    static bool MYGA_L_SPHERE;
    static double MYGA_SPHERE_RADIUS;
    static int MYGA_COUNT_MIN;
    static int CURR_GEN;
    static double MYGA_BH_INIT;
    static double MYGA_BH_INCR;
    static double MYGA_BH_STEPS;
    static bool MYGA_DUMP_POP;
    static bool MYGA_TWIN;
};

// Initialize static members
int MYGA_PARAMS::MYGA_NSTRUC, MYGA_PARAMS::MYGA_NOFF;
int MYGA_PARAMS::MYGA_NMUT = 0;
int MYGA_PARAMS::MYGA_GENS;
int MYGA_PARAMS::MYGA_TOURN_SIZE = 3;
bool MYGA_PARAMS::MYGA_L_EPOCH = false;
int MYGA_PARAMS::MYGA_EPOCH_SAVE = 0;
bool MYGA_PARAMS::MYGA_EPOCH_DUMP = false;
int MYGA_PARAMS::MYGA_COUNT_EPOCH = 1;
double MYGA_PARAMS::MYGA_MUT_RATE = 0.1;
int MYGA_PARAMS::MYGA_CROSS = 1;
double MYGA_PARAMS::MYGA_BQMAX, MYGA_PARAMS::MYGA_CQMAX;
double MYGA_PARAMS::MYGA_DUPLICATE_ETHRESH = 0;
double MYGA_PARAMS::MYGA_DUPLICATE_GTHRESH = 0.174532925;
double MYGA_PARAMS::MYGA_EPOCH_THRESH = 0.01;
double MYGA_PARAMS::MYGA_LAST_ENERGY = 1E10;
bool MYGA_PARAMS::MYGA_L_ROUL = false;
bool MYGA_PARAMS::MYGA_L_CHAIN = false;
bool MYGA_PARAMS::MYGA_L_SPHERE = false;
double MYGA_PARAMS::MYGA_SPHERE_RADIUS = 3.0;
int MYGA_PARAMS::MYGA_COUNT_MIN = 0;
int MYGA_PARAMS::CURR_GEN = 0;
double MYGA_PARAMS::MYGA_BH_INIT;
double MYGA_PARAMS::MYGA_BH_INCR = 0;
double MYGA_PARAMS::MYGA_BH_STEPS;
bool MYGA_PARAMS::MYGA_DUMP_POP = false;
bool MYGA_PARAMS::MYGA_TWIN = false;

// Test functions
void test_MYGA_TOURN_SIZE() {
    if (MYGA_PARAMS::MYGA_TOURN_SIZE == 3) {
        std::cout << "Test MYGA_TOURN_SIZE Passed" << std::endl;
    } else {
        std::cout << "Test MYGA_TOURN_SIZE Failed" << std::endl;
    }
}

void test_MYGA_L_EPOCH() {
    if (!MYGA_PARAMS::MYGA_L_EPOCH) {
        std::cout << "Test MYGA_L_EPOCH Passed" << std::endl;
    } else {
        std::cout << "Test MYGA_L_EPOCH Failed" << std::endl;
    }
}

void test_MYGA_MUT_RATE() {
    if (MYGA_PARAMS::MYGA_MUT_RATE == 0.1) {
        std::cout << "Test MYGA_MUT_RATE Passed" << std::endl;
    } else {
        std::cout << "Test MYGA_MUT_RATE Failed" << std::endl;
    }
}

int main() {
    test_MYGA_TOURN_SIZE();
    test_MYGA_L_EPOCH();
    test_MYGA_MUT_RATE();
    return 0;
}