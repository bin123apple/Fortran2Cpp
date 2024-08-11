#include <iostream>
#include <vector>

// Assuming definitions for the types module (types.h equivalent)
class grid_comm_pattern_type {
public:
    struct send_type {
        std::vector<int> index_no;
    };
    std::vector<send_type> send;
};

class t_comm_variable {
public:
    grid_comm_pattern_type grid_comm_pattern;
};

class bbstr {
    // Assuming some simple members for illustration
public:
    int dummy;
};

// globals.h content merged here
namespace globals {

    const int base = 23;
    double number = 0;
    std::vector<t_comm_variable> comm_variable;
    bbstr bv[2];

    void set(double new_value) {
        number = number + base + new_value;
    }

    double get() {
        return number;
    }

    void init_comm_variable() {
        comm_variable.resize(2);
        for (auto& cv : comm_variable) {
            cv.grid_comm_pattern.send.resize(2);
            for (auto& s : cv.grid_comm_pattern.send) {
                s.index_no.resize(2);
            }
        }
    }

} // namespace globals

// Example usage and simple test
int main() {
    using namespace globals;

    set(10);
    std::cout << "Expected number: 33, Actual number: " << get() << std::endl;

    init_comm_variable();
    if (comm_variable.size() == 2 &&
        comm_variable[0].grid_comm_pattern.send.size() == 2 &&
        comm_variable[0].grid_comm_pattern.send[0].index_no.size() == 2) {
        std::cout << "Initialization of comm_variable is correct." << std::endl;
    } else {
        std::cerr << "Initialization of comm_variable failed." << std::endl;
    }

    return 0;
}