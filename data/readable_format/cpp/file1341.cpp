#include <iostream>
#include <iomanip>
#include <cmath>

void timout(int nout, double tim) {
    int idays, ihours, imins;
    double mins, days, hours, secs;

    days = tim / 86400.0;
    idays = static_cast<int>(days);
    hours = (days - static_cast<double>(idays)) * 24.0;
    ihours = static_cast<int>(hours);
    mins = (hours - static_cast<double>(ihours)) * 60.0;
    imins = static_cast<int>(mins);
    secs = (mins - static_cast<double>(imins)) * 60.0;

    std::ostream& out = (nout == 1) ? std::cout : std::cerr; // Simple nout handling: 1 for cout, other values for cerr

    if (idays > 1) {
        out << std::setw(10) << "" << "COMPUTATION TIME = " << idays << " DAYS " << ihours 
            << " HOURS " << imins << " MINUTES AND " << std::fixed << std::setprecision(3) 
            << secs << " SECONDS";
    } else if (idays == 1) {
        out << std::setw(10) << "" << "COMPUTATION TIME = " << idays << " DAY " << ihours 
            << " HOURS " << imins << " MINUTES AND " << std::fixed << std::setprecision(3) 
            << secs << " SECONDS";
    } else if (ihours > 0) {
        out << std::setw(10) << "" << "COMPUTATION TIME = " << ihours << " HOURS " << imins 
            << " MINUTES AND " << std::fixed << std::setprecision(3) << secs << " SECONDS";
    } else if (imins > 0) {
        out << std::setw(10) << "" << "COMPUTATION TIME = " << imins << " MINUTES AND " 
            << std::fixed << std::setprecision(3) << secs << " SECONDS";
    } else {
        out << std::setw(10) << "" << "COMPUTATION TIME = " << std::fixed 
            << std::setprecision(3) << secs << " SECONDS";
    }
    out << std::endl; // Move to new line after output
}

void test_timout(double tim) {
    timout(1, tim);
}

int main() {
    test_timout(90061.5);  // More than a day
    test_timout(3600.0);   // Exactly one hour
    test_timout(60.0);     // Exactly one minute
    test_timout(30.0);     // Less than a minute
    test_timout(86400.0);  // Exactly one day

    return 0;
}