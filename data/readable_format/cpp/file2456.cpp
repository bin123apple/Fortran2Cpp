// calc_time.cpp
#include <iostream>
#include <cmath>

void calc_time(double& ds, double dsmin, double& dt, double dtmin, double& tss, double tseas, 
               double& ts, double& tt, double dxyz, double dstep, int iter, double& rb, double& dsc) {
    if (ds == dsmin) {
        dt = dtmin;
    } else {
        dt = ds * dxyz;
    }

    if (dt < 0.0) {
        std::cerr << "dt=" << dt << std::endl;
        exit(49673);
    }

    if (tss + dt / tseas * static_cast<double>(iter) >= static_cast<double>(iter)) {
        dt = (std::floor(ts) + 1.0) * tseas - tt;
        tt = (std::floor(ts) + 1.0) * tseas;
        ts = std::floor(ts) + 1.0;
        tss = static_cast<double>(iter);
        ds = dt / dxyz;
    } else {
        tt = tt + dt;
        if (dt == dtmin) {
            ts = ts + dstep;
            tss = tss + 1.0;
        } else {
            ts = ts + dt / tseas;
            tss = tss + dt / tseas * static_cast<double>(iter);
        }
    }

    dsc = ds; // Ensure dsc is updated correctly
    rb = 1.0 - ts;
}

int main() {
    double ds = 1.0, dsmin = 0.1, dt, dtmin = 0.01, tss = 0.0, tseas = 1.0, ts = 0.0, tt = 0.0, dxyz = 0.1, dstep = 0.1;
    int iter = 10;
    double rb, dsc;

    calc_time(ds, dsmin, dt, dtmin, tss, tseas, ts, tt, dxyz, dstep, iter, rb, dsc);

    std::cout << "ds = " << ds << std::endl;
    std::cout << "dt = " << dt << std::endl;
    std::cout << "tss = " << tss << std::endl;
    std::cout << "ts = " << ts << std::endl;
    std::cout << "tt = " << tt << std::endl;
    std::cout << "rb = " << rb << std::endl;
    std::cout << "dsc = " << dsc << std::endl;

    return 0;
}