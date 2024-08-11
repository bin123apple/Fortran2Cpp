#include <iostream>
#include <omp.h>

// Define the MY_TYPE structure
struct MY_TYPE {
    int X;
};

// Function prototype for FOO
void FOO(MY_TYPE var);

// Main program
int main() {
    MY_TYPE var;
    var.X = -1;  // Initialize var.X to -1

    FOO(var);  // Call the FOO function

    // Check the value of var.X
    if (var.X != -1) {
        std::cerr << "Error: var.X is not -1" << std::endl;
        return 1;
    }

    return 0;
}

// Function definition for FOO
void FOO(MY_TYPE var) {
    // OpenMP task with firstprivate(var)
    #pragma omp task firstprivate(var)
    {
        var.X = 1;  // Modify var.X inside the task
    }

    #pragma omp taskwait  // Wait for all tasks to complete
}