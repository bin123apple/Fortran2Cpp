#include <iostream>
#include <vector>
#include <algorithm>

class MovingGate {
public:
    MovingGate(double timeVal, double tgateVal, double VXgateVal, double VZgateVal, double dtVal, double zmaxIniVal, int ngateIni, int ngateEnd)
        : time(timeVal), tgate(tgateVal), VXgate(VXgateVal), VZgate(VZgateVal), dt(dtVal), zmax_ini(zmaxIniVal),
          ngate_ini(ngateIni), ngate_end(ngateEnd), xp(ngateEnd, 0.0), zp(ngateEnd, 0.0), up(ngateEnd, 0.0), wp(ngateEnd, 0.0) {
              // Initialize zp with specific values to match Fortran test
              zp[0] = 0.0; zp[1] = 5.0; zp[2] = 11.0; // Adjust for 0-based indexing
          }
    
    void movingGate() {
        for (int i = ngate_ini; i < ngate_end; ++i) {
            if (time >= tgate) {
                xp[i] = xp[i] + VXgate * dt;
                zp[i] = std::min(zp[i] + VZgate * dt, zmax_ini);
                
                up[i] = VXgate;
                wp[i] = VZgate;
            }
        }
    }

    void printResults() {
        std::cout << "C++ Testing MovingGate:" << std::endl;
        for (int i = 0; i < 3; ++i) {
            std::cout << "Particle " << i + 1 << std::endl;
            std::cout << "  xp: " << xp[i] << std::endl;
            std::cout << "  zp: " << zp[i] << std::endl;
            std::cout << "  up: " << up[i] << std::endl;
            std::cout << "  wp: " << wp[i] << std::endl;
        }
    }

private:
    double time, VXgate, VZgate, dt, tgate, zmax_ini;
    int ngate_ini, ngate_end;
    std::vector<double> xp, zp, up, wp;
};

int main() {
    // Set up a MovingGate instance with some test values
    MovingGate mg(5.0, 4.0, 1.0, 2.0, 0.1, 10.0, 0, 3);
    
    // Initialize positions and velocities
    mg.movingGate();
    
    // Test and print outputs
    mg.printResults();

    return 0;
}