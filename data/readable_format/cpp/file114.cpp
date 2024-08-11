#include <iostream>
#include <fstream>
#include <string>

void createXML(const std::string& filename) {
    std::ofstream outFile(filename);
    
    if (outFile) {
        // Correctly escape double quotes within string literals
        outFile << R"(<?xml version="1.0" encoding="UTF-8"?>)" << std::endl;
        outFile << "<!DOCTYPE html>" << std::endl;
        // Correct the placement of quotes around URL
        outFile << R"(<!-- Parameter Entity: copy "http://www.uszla.me.uk/entities" -->)" << std::endl;
        outFile << "<html>" << std::endl;
        outFile << "</html>" << std::endl;
    } else {
        std::cerr << "Could not open file for writing." << std::endl;
    }

    outFile.close();
}

bool checkXML(const std::string& filename) {
    std::ifstream inFile(filename);
    std::string line;
    bool doctypeFound = false, paramEntityFound = false, htmlTagFound = false;

    if (inFile) {
        while (std::getline(inFile, line)) {
            if (line.find("<!DOCTYPE html>") != std::string::npos) doctypeFound = true;
            if (line.find(R"(<!-- Parameter Entity: copy "http://www.uszla.me.uk/entities" -->)") != std::string::npos) paramEntityFound = true;
            if (line.find("<html>") != std::string::npos) htmlTagFound = true;
        }
    } else {
        std::cerr << "Could not open file for reading." << std::endl;
        return false;
    }

    inFile.close();
    
    return doctypeFound && paramEntityFound && htmlTagFound;
}

int main() {
    std::string filename = "test.xml";
    
    createXML(filename);
    
    if (checkXML(filename)) {
        std::cout << "XML file passed verification checks." << std::endl;
    } else {
        std::cerr << "XML file failed verification checks." << std::endl;
    }
    
    return 0;
}