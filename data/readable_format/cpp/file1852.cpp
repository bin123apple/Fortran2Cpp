#include <iostream>

int Juldy(int Imon, int Id, int Iy) {
    // Define the total days in the months up to the given month (excluding it)
    int ITD[] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

    // Check for valid date ranges
    if (Iy < 1800 || Imon < 1 || Imon > 12) {
        return -999;
    }

    // Start counting days with the given day
    int JulDy = Id;
    if (Imon == 1) {
        return JulDy;
    }

    // Add the days from the previous months
    JulDy += ITD[Imon - 2];

    // Check for leap year and adjust if necessary
    if (Imon >= 3 && Iy % 4 == 0 && (Iy % 400 == 0 || Iy % 100 != 0)) {
        JulDy += 1;
    }

    return JulDy;
}

int main() {
    int month = 3; // Example month
    int day = 15;  // Example day
    int year = 2020; // Example year

    // Call the Juldy function and print the result
    int julianDay = Juldy(month, day, year);
    std::cout << "Julian day: " << julianDay << std::endl;

    return 0;
}