#include <iostream>
#include <string>

// Equivalent to m_common_charset
enum XMLVersion {
    XML1_0,
    XML1_1
};

// Equivalent to xml_doc_state structure in m_common_struct
struct XmlDocumentState {
    XMLVersion xml_version = XML1_0; // Default to XML 1.0
};

// Placeholder for checkQName functionality
bool checkQName(const std::string& name, const XmlDocumentState& xds) {
    // Actual implementation should check the name according to xds.xml_version
    // Placeholder implementation for demonstration
    if (name.empty() || isdigit(name[0]) || name[0] == ':' || name[0] == '#') {
        return false;
    }
    if (name.find(':') != std::string::npos && xds.xml_version == XML1_0) {
        return false;
    }
    return true;
}

int main() {
    XmlDocumentState xds;

    std::cout << std::boolalpha; // Print bools as true/false

    // Test QName validation before changing XML version
    std::cout << "Testing with XML 1.0" << std::endl;
    std::cout << checkQName("abcd", xds) << std::endl;
    std::cout << checkQName("1abcd", xds) << std::endl;
    std::cout << checkQName(":abcd", xds) << std::endl;
    std::cout << checkQName("#abcd", xds) << std::endl;
    std::cout << checkQName("e:abcd", xds) << std::endl;

    // Change XML version to 1.1 and test again
    xds.xml_version = XML1_1;
    std::cout << "Testing with XML 1.1" << std::endl;
    std::cout << checkQName("abcd", xds) << std::endl;
    std::cout << checkQName("1abcd", xds) << std::endl;
    std::cout << checkQName(":abcd", xds) << std::endl;
    std::cout << checkQName("#abcd", xds) << std::endl;
    std::cout << checkQName("e:abcd", xds) << std::endl;

    return 0;
}