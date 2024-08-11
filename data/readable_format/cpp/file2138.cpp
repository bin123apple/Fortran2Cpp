#include <string>

class Formats {
public:
    static const std::string OFMT1;
    static const std::string OFMT2;
    static const std::string OFMT3;
    static const std::string OFMT4;
    static const std::string OFTM44;
    static const std::string OFMT71;
};

// Definition of static members
const std::string Formats::OFMT1 = "(3E30.16E3)";
const std::string Formats::OFMT2 = "(34E30.16E3)";
const std::string Formats::OFMT3 = "(7E30.16E3)";
const std::string Formats::OFMT4 = "(7E30.16E3)";
const std::string Formats::OFTM44 = "(66E30.16E3)";
const std::string Formats::OFMT71 = "(71E30.16E3)";