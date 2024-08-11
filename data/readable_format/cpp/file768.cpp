#include <array>
#include <string>
#include <iostream>
#include <cassert>

// Assuming the Isochrones class definition is provided elsewhere in the code.
// If not, you need to include or define the Isochrones class as well.

class Isochrones {
public:
    static constexpr int niso = 9;
    static const std::array<std::string, niso> isofile;
};

const std::array<std::string, Isochrones::niso> Isochrones::isofile = {
    "isochrones/UBVRIJHKsKp/fehm25afep0.UBVRIJHKsKp",
    "isochrones/UBVRIJHKsKp/fehm20afep0.UBVRIJHKsKp",
    "isochrones/UBVRIJHKsKp/fehm15afep0.UBVRIJHKsKp",
    "isochrones/UBVRIJHKsKp/fehm10afep0.UBVRIJHKsKp",
    "isochrones/UBVRIJHKsKp/fehm05afep0.UBVRIJHKsKp",
    "isochrones/UBVRIJHKsKp/fehp00afep0.UBVRIJHKsKp",
    "isochrones/UBVRIJHKsKp/fehp02afep0.UBVRIJHKsKp",
    "isochrones/UBVRIJHKsKp/fehp03afep0.UBVRIJHKsKp",
    "isochrones/UBVRIJHKsKp/fehp05afep0.UBVRIJHKsKp"
};

int main() {
    std::array<std::string, 9> expectedPaths = {
        "isochrones/UBVRIJHKsKp/fehm25afep0.UBVRIJHKsKp",
        "isochrones/UBVRIJHKsKp/fehm20afep0.UBVRIJHKsKp",
        "isochrones/UBVRIJHKsKp/fehm15afep0.UBVRIJHKsKp",
        "isochrones/UBVRIJHKsKp/fehm10afep0.UBVRIJHKsKp",
        "isochrones/UBVRIJHKsKp/fehm05afep0.UBVRIJHKsKp",
        "isochrones/UBVRIJHKsKp/fehp00afep0.UBVRIJHKsKp",
        "isochrones/UBVRIJHKsKp/fehp02afep0.UBVRIJHKsKp",
        "isochrones/UBVRIJHKsKp/fehp03afep0.UBVRIJHKsKp",
        "isochrones/UBVRIJHKsKp/fehp05afep0.UBVRIJHKsKp"
    };

    for (size_t i = 0; i < Isochrones::niso; ++i) {
        assert(Isochrones::isofile[i] == expectedPaths[i]);
    }

    std::cout << "All tests passed.";

    return 0;
}