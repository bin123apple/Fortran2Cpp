#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>

// Function declaration
void timestamp();

int main() {
    // Test the timestamp function
    timestamp();
    // Additional tests can be performed here by calling timestamp() again if needed.
    return 0;
}

// Function definition
void timestamp() {
    std::string ampm;
    std::string month[12] = {
        "January  ", "February ", "March    ", "April    ",
        "May      ", "June     ", "July     ", "August   ",
        "September", "October  ", "November ", "December "
    };

    // Get current time
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    int y = now->tm_year + 1900; // tm_year is years since 1900
    int m = now->tm_mon; // tm_mon is months since January [0,11]
    int d = now->tm_mday;
    int h = now->tm_hour;
    int n = now->tm_min;
    int s = now->tm_sec;

    // Handling AM/PM
    if (h < 12) {
        ampm = "AM";
    } else if (h == 12) {
        if (n == 0 && s == 0) {
            ampm = "Noon";
        } else {
            ampm = "PM";
        }
    } else {
        h -= 12;
        if (h == 0) h = 12; // Convert 0 hour to 12 for 12-hour format
        ampm = "PM";
    }

    // Print formatted timestamp
    std::cout << month[m] << " " << std::setfill('0') << std::setw(2) << d << " " << y << " "
              << std::setw(2) << h << ":" << std::setw(2) << n << ":" << std::setw(2) << s
              << " " << ampm << std::endl;
}