#include <iostream>
#include <string>
#include <cctype> // for std::tolower

void caps(std::string& file_name) {
    std::string temp_name = file_name;
    
    // Convert uppercase to lowercase
    for (char& c : temp_name) {
        c = std::tolower(static_cast<unsigned char>(c));
    }
    
    // Trim leading spaces
    size_t firstNonSpace = temp_name.find_first_not_of(' ');
    if (firstNonSpace != std::string::npos) {
        temp_name = temp_name.substr(firstNonSpace);
    }

    file_name = temp_name;
}

// Example usage
int main() {
    std::string file_name = "  HELLO WORLD.TXT";
    caps(file_name);
    std::cout << "Converted and trimmed string: '" << file_name << "'" << std::endl;
    return 0;
}