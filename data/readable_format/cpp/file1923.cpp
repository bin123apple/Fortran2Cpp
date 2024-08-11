#include <complex>
using namespace std;

double SCABS1(const complex<double>& Z) {
    return abs(real(Z)) + abs(imag(Z));
}