#include <iostream>

// Consolidated namespace for no_endmodule_m1
namespace no_endmodule_m1 {
    int a = 0; // Assuming an initial value, can be modified as needed
}

// Consolidated namespace for no_endmodule_m2
namespace no_endmodule_m2 {
    int b = 0; // Assuming an initial value, can be modified as needed
}

int main() {
    // Assigning values for demonstration
    no_endmodule_m1::a = 5;
    no_endmodule_m2::b = 10;

    // Using the variables from the modules
    std::cout << no_endmodule_m1::a << " " << no_endmodule_m2::b << std::endl;

    return 0;
}