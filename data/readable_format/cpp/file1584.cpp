#include <iostream>
#include <vector>

const int nelemg = 1;  // Adjusted to match Fortran example
const int nume = 1;    // Adjusted to match Fortran example

struct MaterialProperties {
    std::vector<float> Y_modulus;
    std::vector<float> possion_ratio;
    MaterialProperties() : Y_modulus(nume, 210.0f), possion_ratio(nume, 0.3f) {}
} materialProperties;

struct DeformationSigns {
    std::vector<float> sign1;
    std::vector<float> sign2;
    std::vector<float> sign3;
    std::vector<float> sign4;
    DeformationSigns() : sign1(nelemg, 0.1f), sign2(nelemg, 0.2f), sign3(nelemg, 0.3f), sign4(nelemg, 0.4f) {}
} deformationSigns;

int nftm1 = 0;

void elastic_energy(int ele, float& qe) {
    int ink = ele + nftm1 - 1;  // Adjust for 0-based indexing in C++
    float E = materialProperties.Y_modulus[ink];
    float v = materialProperties.possion_ratio[ink];
    
    float epx = (1 + v) / E * ((1 - v) * deformationSigns.sign1[ele - 1] - v * deformationSigns.sign2[ele - 1]);
    float epy = (1 + v) / E * (-v * deformationSigns.sign1[ele - 1] + (1 - v) * deformationSigns.sign2[ele - 1]);
    float epxy = (1 + v) / E * 2 * deformationSigns.sign4[ele - 1];
    
    qe = (deformationSigns.sign1[ele - 1] * epx + deformationSigns.sign2[ele - 1] * epy + deformationSigns.sign4[ele - 1] * epxy) / 2.0;
}

int main() {
    int ele = 1;  // Testing the first element
    float qe = 0.0f;
    elastic_energy(ele, qe);

    std::cout << "Computed elastic energy: " << qe << std::endl;

    return 0;
}