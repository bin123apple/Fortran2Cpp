#include <iostream>
#include <array>
#include <string>
#include <cassert>

// Assuming nrtype.h defines types such as I4B, but since we're integrating everything into a single file,
// let's define I4B directly here for simplicity. You might need to adjust this based on actual definitions.
using I4B = int; // Example definition, replace with the actual type if different.

// Constants
const std::string FUSE_version = "FUSE 1.0";
const bool FUSE_enabled = true;
const int NDEC = 9;
const int NTDH_MAX = 500;

// DESC type
struct DESC {
    std::string MCOMPONENT; // Adjusted size in constructor
    DESC() : MCOMPONENT(16, ' ') {} // Initialize with 16 spaces
};

// UMODEL type
struct UMODEL {
    int MODIX;
    std::string MNAME; // Adjusted size in constructor
    int iRFERR, iARCH1, iARCH2, iQSURF, iQPERC, iESOIL, iQINTF, iQ_TDH, iSNOWM;

    UMODEL() : MNAME(256, ' '), MODIX(0), iRFERR(0), iARCH1(0), iARCH2(0), iQSURF(0), iQPERC(0), iESOIL(0), iQINTF(0), iQ_TDH(0), iSNOWM(0) {}
};

// SNAMES type
struct SNAMES {
    int iSNAME;
};

// FNAMES type
struct FNAMES {
    std::string FNAME; // Adjusted size in constructor
    FNAMES() : FNAME(16, ' ') {}
};

// Global variables / equivalent module variables
std::array<DESC, 2> LIST_RFERR;
std::array<DESC, 3> LIST_ARCH1;
std::array<DESC, 4> LIST_ARCH2;
std::array<DESC, 3> LIST_QSURF;
std::array<DESC, 3> LIST_QPERC;
std::array<DESC, 2> LIST_ESOIL;
std::array<DESC, 2> LIST_QINTF;
std::array<DESC, 2> LIST_Q_TDH;
std::array<DESC, 2> LIST_SNOWM;

std::array<UMODEL, 5000> AMODL;
UMODEL SMODL;

std::array<SNAMES, 7> CSTATE;
int NSTATE = 0;

std::array<FNAMES, 50> C_FLUX;
int N_FLUX = 0;

// Test functions
void testDESC() {
    DESC testDesc;
    testDesc.MCOMPONENT = "TestComponent";
    assert(testDesc.MCOMPONENT == "TestComponent");
    std::cout << "DESC Test Passed." << std::endl;
}

void testUMODEL() {
    UMODEL testModel;
    testModel.MNAME = "TestModel";
    assert(testModel.MNAME == "TestModel");
    std::cout << "UMODEL Test Passed." << std::endl;
}

// Main function
int main() {
    testDESC();
    testUMODEL();
    std::cout << "All C++ tests done." << std::endl;
    return 0;
}