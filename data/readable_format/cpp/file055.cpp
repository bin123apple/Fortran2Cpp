#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <string>

// Function prototype
void printTimestamp(int y, int m, int d, int h, int n, int s, std::string& ampm, std::string& formattedTime);

// Simple test function prototype
void runTests();

int main() {
    runTests();
    return 0;
}

void printTimestamp(int y, int m, int d, int h, int n, int s, std::string& ampm, std::string& formattedTime) {
    std::string month[] = {
        "January  ", "February ", "March    ", "April    ",
        "May      ", "June     ", "July     ", "August   ",
        "September", "October  ", "November ", "December "
    };
    
    if (h >= 12) {
        ampm = (h == 12 && n == 0 && s == 0) ? "Noon" : "PM";
    } else {
        ampm = (h == 0 && n == 0 && s == 0) ? "Midnight" : "AM";
    }

    int displayHour = h % 12;
    if (displayHour == 0) displayHour = 12;

    std::ostringstream ss;
    ss << std::setfill('0') << std::setw(2) << d << " "
       << month[m - 1] << " " << y << "  "
       << std::setw(2) << displayHour << ":" << std::setw(2) << n << ":"
       << std::setw(2) << s << " " << ampm;

    formattedTime = ss.str();
}

void runTests() {
    std::string ampm, formattedTime;
    
    // Test Case 1: Noon
    printTimestamp(2023, 4, 15, 12, 0, 0, ampm, formattedTime);
    std::cout << "Test Noon: " << formattedTime << std::endl;
    
    // Test Case 2: Midnight
    printTimestamp(2023, 4, 15, 0, 0, 0, ampm, formattedTime);
    std::cout << "Test Midnight: " << formattedTime << std::endl;
    
    // Test Case 3: General PM Time
    printTimestamp(2023, 4, 15, 15, 45, 30, ampm, formattedTime);
    std::cout << "Test 3:15 PM: " << formattedTime << std::endl;

    // Add more test cases as necessary
}