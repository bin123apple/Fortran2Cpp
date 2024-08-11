#include <iostream>
#include <vector>

class ModuleGeometry {
public:
    int Nnco, Nnco0, Nncoold;
    int Npf, Npb, Npo;
    int Nsamp, Nsampold;
    double Ls, Ls0, Lsold;   
    double Lx, Lx0, Lxold;   

    std::vector<int> oxrow, oxsum;
    std::vector<int> pbrow, pbsum;
    std::vector<int> whereisnode;

    std::vector<double> x, y, x0, y0;
    std::vector<double> xo, yo;
    std::vector<double> xb, yb;
    std::vector<double> s;
    std::vector<double> th;
    std::vector<double> c;
    std::vector<double> dU;
    std::vector<double> E;

    ModuleGeometry() : Nnco(0), Nnco0(0), Nncoold(0), Npf(0), Npb(0), Npo(0), Nsamp(0), Nsampold(0),
                       Ls(0.0), Ls0(0.0), Lsold(0.0), Lx(0.0), Lx0(0.0), Lxold(0.0) {}
};

int main() {
    ModuleGeometry geom;

    geom.Nnco = 5;
    geom.Ls = 3.14;

    geom.oxrow.resize(10);
    geom.x.resize(10);

    for (int i = 0; i < 10; ++i) {
        geom.oxrow[i] = i + 1;
        geom.x[i] = 0.1 * (i + 1);
    }

    std::cout << "Nnco: " << geom.Nnco << std::endl;
    std::cout << "Ls: " << geom.Ls << std::endl;
    std::cout << "oxrow: ";
    for (const auto& val : geom.oxrow) std::cout << val << " ";
    std::cout << std::endl;
    std::cout << "x: ";
    for (const auto& val : geom.x) std::cout << val << " ";
    std::cout << std::endl;

    return 0;
}