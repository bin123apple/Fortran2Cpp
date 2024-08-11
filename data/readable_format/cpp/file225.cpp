#include <string>
#include <array>

int main() {
    const int nfit = 18;
    std::array<std::string, nfit> titles = {
        "SMA", "PMA", "SRA", "PRA", "PER",
        "INC", "EPO", "ZPT", "ALB", "NL1",
        "NL2", "NL3", "NL4", "ECW", "ESW",
        "TED", "VOF", "DIL"
    };

    // Example usage: print all titles
    for (const auto& title : titles) {
        std::cout << title << std::endl;
    }

    return 0;
}