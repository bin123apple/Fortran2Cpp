#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

int main() {
    const int N = 10;
    std::vector<std::string> ca(3);
    std::ostringstream buffer;

    ca[0] = "foo";
    ca[1] = "bar";
    ca[2] = "xyzzy";

    for (const auto& str : ca) {
        buffer << std::setw(5) << std::left << str;
    }

    std::string result = buffer.str();
    result = result.substr(0, result.find_last_not_of(' ') + 1);

    if (result != "foo  bar  xyzzy") {
        return 1;
    }

    return 0;
}