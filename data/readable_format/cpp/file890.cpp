#include <gtest/gtest.h>
#include <fstream>
#include <array>
#include <iomanip>
#include <string>
#include <sstream>

// Function to write latitude and longitude data to a file
void write_latlong_data(const std::array<double, 2>& lat, const std::array<double, 2>& longitude) {
    std::ofstream file("latlong.dat");

    if (file) {
        // Set precision and scientific notation as in the original Fortran code
        file << std::scientific << std::setprecision(16);

        // Writing the latitude and longitude to the file
        file << std::setw(24) << lat[0] << std::setw(24) << lat[1]
             << std::setw(24) << longitude[0] << std::setw(24) << longitude[1] << std::endl;

        file.close();
    } else {
        // Handle file opening error
        std::cerr << "Error: Unable to open file for writing." << std::endl;
    }
}

// Test case to verify the write_latlong_data function
TEST(LatLongWriteTest, CorrectFormatAndPrecision) {
    // Test data
    std::array<double, 2> lat = {35.6895, 40.7128};
    std::array<double, 2> longitude = {139.6917, -74.0060};

    // Write data
    write_latlong_data(lat, longitude);

    // Read data back
    std::ifstream file("latlong.dat");
    ASSERT_TRUE(file.is_open());

    std::string line;
    std::getline(file, line);
    file.close();

    // Build expected string
    std::stringstream expected;
    expected << std::scientific << std::setprecision(16);
    expected << std::setw(24) << lat[0] << std::setw(24) << lat[1]
             << std::setw(24) << longitude[0] << std::setw(24) << longitude[1];

    // Compare
    EXPECT_EQ(line, expected.str());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}