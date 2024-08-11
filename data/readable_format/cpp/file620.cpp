#include <gtest/gtest.h>
#include <fstream>
#include <iostream>
#include <string>

// GenerateKML function creates a simple KML file for testing
void GenerateKML(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    file << R"(<?xml version="1.0" encoding="UTF-8"?>)" << std::endl;
    file << R"(<kml xmlns="http://www.opengis.net/kml/2.2">)" << std::endl;
    file << "<Document>" << std::endl;
    file << "<Placemark>" << std::endl;
    file << "<name>Simple Placemark</name>" << std::endl;
    file << "<Point>" << std::endl;
    file << "<coordinates>-122.0822035425683,37.42228990140251,0</coordinates>" << std::endl;
    file << "</Point>" << std::endl;
    file << "</Placemark>" << std::endl;
    file << "</Document>" << std::endl;
    file << "</kml>" << std::endl;

    file.close();
}

// Test case to verify the creation and basic content of the KML file
TEST(KMLGenerationTest, FileCreation) {
    std::string filename = "test_kml.xml";
    GenerateKML(filename);

    std::ifstream file(filename);
    ASSERT_TRUE(file.good()) << "KML file was not created.";

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    EXPECT_NE(content.find("<kml"), std::string::npos) << "KML file does not contain expected content.";
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}