#include <iostream>
#include <vector>
#include <string>

using DOUBLE = double;

// Example of a basic structure to handle 2D arrays/matrix operations.
class Matrix {
public:
    DOUBLE** data;
    int rows, cols;

    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data = new DOUBLE*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new DOUBLE[cols];
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    DOUBLE* operator[](int row) {
        return data[row];
    }

    const DOUBLE* operator[](int row) const {
        return data[row];
    }
};

// Define a simple vector structure for 3D vectors.
class Vector3 {
public:
    DOUBLE x, y, z;

    Vector3(DOUBLE x = 0, DOUBLE y = 0, DOUBLE z = 0) : x(x), y(y), z(z) {}

    void print() const {
        std::cout << x << " " << y << " " << z << std::endl;
    }
};

void drcout(const Matrix& XYZ3, const Matrix& GEO3, const Matrix& VEL3, 
            int NVAR, DOUBLE TIME, const Vector3& ESCF3, const Vector3& EKIN3, 
            const Vector3& ETOT3, const Vector3& XTOT3, int ILOOP, 
            const std::vector<DOUBLE>& CHARGE, DOUBLE FRACT, const std::string& TEXT1, 
            const std::string& TEXT2, int II, int& JLOOP) {

    std::cout << "XYZ3:" << std::endl;
    for (int i = 0; i < XYZ3.rows; ++i) {
        for (int j = 0; j < XYZ3.cols; ++j) {
            std::cout << XYZ3[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Similar print blocks for GEO3 and VEL3 can be added

    std::cout << "TIME: " << TIME << std::endl;
    std::cout << "ESCF3: "; ESCF3.print();
    std::cout << "EKIN3: "; EKIN3.print();
    std::cout << "ETOT3: "; ETOT3.print();
    std::cout << "XTOT3: "; XTOT3.print();
    std::cout << "ILOOP: " << ILOOP << std::endl;

    std::cout << "CHARGE: ";
    for (DOUBLE charge : CHARGE) std::cout << charge << " ";
    std::cout << std::endl;

    std::cout << "FRACT: " << FRACT << std::endl;
    std::cout << "TEXT1: " << TEXT1 << std::endl;
    std::cout << "TEXT2: " << TEXT2 << std::endl;
    std::cout << "II: " << II << std::endl;
    std::cout << "JLOOP: " << JLOOP << std::endl;
}

int main() {
    int NVAR = 3;
    Matrix XYZ3(NVAR, 3), GEO3(NVAR, 3), VEL3(NVAR, 3);
    // Fill in the matrices with data
    for (int i = 0; i < NVAR; ++i) {
        for(int j = 0; j < 3; ++j) {
            XYZ3[i][j] = i * NVAR + j + 1;
            GEO3[i][j] = i * NVAR + j + 1.1;
            VEL3[i][j] = 0.1 * (i * NVAR + j + 1);
        }
    }
    DOUBLE TIME = 10.0;
    Vector3 ESCF3(1.0, 2.0, 3.0), EKIN3(4.0, 5.0, 6.0), ETOT3(7.0, 8.0, 9.0), XTOT3(10.0, 11.0, 12.0);
    int ILOOP = 2;
    std::vector<DOUBLE> CHARGE = {0.5, 0.6, 0.7};
    DOUBLE FRACT = 0.3;
    std::string TEXT1 = "ABC";
    std::string TEXT2 = "XY";
    int II = 1;
    int JLOOP = 0;

    drcout(XYZ3, GEO3, VEL3, NVAR, TIME, ESCF3, EKIN3, ETOT3, XTOT3, ILOOP, CHARGE, FRACT, TEXT1, TEXT2, II, JLOOP);

    return 0;
}