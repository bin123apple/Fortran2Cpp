#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

void writeTurnDirections(const std::vector<double>& xn, const std::string& turdir, int nev, int nm) {
    using namespace std;

    cout << endl << "    E I G E N M O D E   T U R N I N G   D I R E C T I O N" << endl << endl;
    cout << "    Axis reference direction:";
    for (auto x : xn) {
        cout << setw(12) << setprecision(4) << scientific << x;
    }
    cout << endl << endl;
    cout << " NODAL   MODE NO     TURNING DIRECTION (F=FORWARD,B=BACKWARD)" << endl;
    cout << "DIAMETER" << endl << endl;

    for (int j = 0; j < nev; ++j) {
        cout << setw(5) << nm << setw(4) << "" << setw(7) << (j + 1) << setw(10) << "" << turdir[j] << endl;
    }
}

int main() {
    std::vector<double> xn = {1.23, 4.56, 7.89};
    std::string turdir = "FBF";
    int nev = 3, nm = 1;

    writeTurnDirections(xn, turdir, nev, nm);
    return 0;
}