#include <iostream>

class JulianDay {
public:
    static int julianDay(int yr, int mo, int da) {
        // Placeholder for the actual implementation of the Julian Day calculation.
        // The actual calculation is not provided in the original Fortran code snippet,
        // so it's omitted here as well. This function should contain the logic to
        // compute and return the Julian Day based on the given year (yr), month (mo),
        // and day (da).

        // Example implementation (simplified and not accurate for all dates):
        int a = (14 - mo) / 12;
        int y = yr + 4800 - a;
        int m = mo + 12 * a - 3;
        int julianDay = da + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;

        return julianDay; // Placeholder return value.
    }
};

int main() {
    // Example usage:
    int year = 2023;
    int month = 9;
    int day = 23;

    int julianDay = JulianDay::julianDay(year, month, day);
    std::cout << "Julian Day: " << julianDay << std::endl;

    return 0;
}