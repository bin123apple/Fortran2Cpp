#include <iostream>
#include <algorithm> // For std::min and std::max
#include <cmath> // For std::fabs

namespace pfc1dfuns2 {
    double F_hp_face(double dxin, double hin, double zin, double dxout, double hout, double zout, double b) {
        double head_at_face = ((hin + zin) * dxin + (hout + zout) * dxout) / (dxin + dxout);
        double Zface = (zin * dxin + zout * dxout) / (dxin + dxout);
        return std::min(b, head_at_face - Zface);
    }

    double F_hs_face(double dxin, double hin, double zin, double dxout, double hout, double zout, double b) {
        double head_at_face = ((hin + zin) * dxin + (hout + zout) * dxout) / (dxin + dxout);
        double Zface = (zin * dxin + zout * dxout) / (dxin + dxout);
        return std::max(0.0, head_at_face - Zface - b);
    }
}

bool areClose(double a, double b, double tolerance = 1e-6) {
    return std::fabs(a - b) < tolerance;
}

int main() {
    double dxin = 2.0, dxout = 3.0, hin = 1.0, hout = 2.0, zin = 0.5, zout = 0.5, b = 1.5;
    double result_hp = pfc1dfuns2::F_hp_face(dxin, hin, zin, dxout, hout, zout, b);
    double result_hs = pfc1dfuns2::F_hs_face(dxin, hin, zin, dxout, hout, zout, b);

    std::cout << "Test F_hp_face Result: " << result_hp << std::endl;
    std::cout << "Test F_hs_face Result: " << result_hs << std::endl;

    // Basic validation
    if (!areClose(result_hp, 1.5)) {
        std::cerr << "Test F_hp_face failed!" << std::endl;
    }
    if (!areClose(result_hs, 0.1)) {
        std::cerr << "Test F_hs_face failed!" << std::endl;
    }
}