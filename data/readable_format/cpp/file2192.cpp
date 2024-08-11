#include <string>
#include <array>

namespace TAB_DATA {
    std::array<std::string, 6> TAB_ERRMSG = {
        "Success",
        "Null tabprm pointer passed",
        "Memory allocation failed",
        "Invalid tabular parameters",
        "One or more of the x coordinates were invalid",
        "One or more of the world coordinates were invalid"
    };
}

int main() {
    // Example usage
    for (const auto& msg : TAB_DATA::TAB_ERRMSG) {
        std::cout << msg << std::endl;
    }
    return 0;
}