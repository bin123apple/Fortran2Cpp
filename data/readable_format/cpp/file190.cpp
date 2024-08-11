#include <iostream>
#include <string>

struct Block_File_Names {
    std::string inPrefix = "";
    std::string outPrefix = "";
    std::string Flow_File = "";
    std::string Heat_File = "";
    std::string Init_File = "";
    std::string Net_File = "";
    std::string NPS_File = "";
    std::string Param_File = "";
    std::string Source_File = "";
    std::string Spatial_File = "";
};

// Function to test the struct
void testBlockFileNames() {
    Block_File_Names fileNames;

    // Assign some values
    fileNames.inPrefix = "input_";
    fileNames.outPrefix = "output_";
    fileNames.Flow_File = "flow.dat";
    fileNames.Heat_File = "heat.dat";
    fileNames.Init_File = "init.dat";
    fileNames.Net_File = "net.dat";
    fileNames.NPS_File = "nps.dat";
    fileNames.Param_File = "param.dat";
    fileNames.Source_File = "source.dat";
    fileNames.Spatial_File = "spatial.dat";

    // Simple testing using if statements and printouts
    if (fileNames.inPrefix == "input_") {
        std::cout << "Test passed for inPrefix" << std::endl;
    } else {
        std::cout << "Test failed for inPrefix" << std::endl;
    }

    // Test for Flow_File
    if (fileNames.Flow_File == "flow.dat") {
        std::cout << "Test passed for Flow_File" << std::endl;
    } else {
        std::cout << "Test failed for Flow_File" << std::endl;
    }

    // Continue with other fields...
}

int main() {
    // Run the test function
    testBlockFileNames();

    return 0;
}