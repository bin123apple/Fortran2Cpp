#include <iostream>
#include <vector>
#include <string>
#include <array>

// Consolidated namespaces with data structure definitions

namespace ExecutionData {
    int doCharge;
    int doVis;
    // Add functions to manipulate ExecutionData here, if needed.
}

namespace AtomData {
    std::string elementName;
    std::array<int, 4> numCoreOrbitals;
    std::array<int, 4> numValeOrbitals;
    std::array<int, 4> numTotalOrbitals;
    std::array<std::array<int, 3>, 4> numValeOrbitalsPerBasis;
    double atomicNumber;
    double nuclearAlpha;
    // Add functions to manipulate AtomData here, if needed.
}

namespace GaussianBasisData {
    int maxNumBasisGaussians;
    std::array<int, 4> numBasisGaussians;
    std::array<int, 4> numBasisTerms;
    std::vector<std::vector<int>> selectGaussians;
    std::vector<std::vector<int>> basisID;
    double minBasisAlpha;
    double maxBasisAlpha;
    std::vector<double> basisAlphas;
    std::vector<std::vector<double>> angNorm1;
    std::vector<std::vector<double>> angNorm2;
    // Add functions to manipulate GaussianBasisData here, if needed.
}

namespace PotGaussianData {
    int numPotGaussians;
    std::vector<double> potAlphas;
    std::vector<double> potCoeffs;
    // Add functions to manipulate PotGaussianData here, if needed.
}

namespace MatrixElementData {
    std::vector<std::vector<std::vector<double>>> overlapME;
    std::vector<std::vector<std::vector<double>>> hamiltonianME;
    // Add functions to manipulate MatrixElementData here, if needed.
}

namespace WaveFunctionData {
    std::vector<std::vector<double>> eigenValues;
    // Add functions to manipulate WaveFunctionData here, if needed.
}

// Main function to demonstrate usage
int main() {
    // Demonstration of setting some data
    ExecutionData::doCharge = 1;
    ExecutionData::doVis = 0;

    AtomData::elementName = "He";
    AtomData::atomicNumber = 2.0;

    // Print out to verify
    std::cout << "ExecutionData::doCharge = " << ExecutionData::doCharge << std::endl;
    std::cout << "AtomData::elementName = " << AtomData::elementName << std::endl;

    // Add further demonstration or testing code as needed

    return 0;
}