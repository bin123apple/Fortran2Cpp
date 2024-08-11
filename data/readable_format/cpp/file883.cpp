#include <string>
#include <array>

// Equivalent of the COMMON block
struct LIN_DATA {
    std::array<std::string, 4> LIN_ERRMSG;

    LIN_DATA() : LIN_ERRMSG{ "Success",
                             "Null linprm pointer passed",
                             "Memory allocation failed",
                             "PCi_ja matrix is singular" } {}
};

// Global instance
LIN_DATA lin_data;

int main() {
    // Example usage
    for (const auto& msg : lin_data.LIN_ERRMSG) {
        std::cout << msg << std::endl;
    }

    return 0;
}