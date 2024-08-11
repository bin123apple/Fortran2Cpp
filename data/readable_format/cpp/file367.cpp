#include <iostream>

// Assuming dummy implementations of the previously separate module functionalities
namespace m_base_test {
    void base_test() {
        std::cout << "Base test." << std::endl;
    }
}

namespace m_dev_test {
    void dev_test() {
        std::cout << "Device test." << std::endl;
    }
}

namespace m_mem_test {
    void mem_test() {
        std::cout << "Memory test." << std::endl;
    }
}

namespace m_knl_test {
    void knl_test() {
        std::cout << "Kernel test." << std::endl;
    }
}

class m_handler {
public:
    static void handler_start() {
        std::cout << "Handler start." << std::endl;
    }

    static void handler_end() {
        std::cout << "Handler end." << std::endl;
    }

    static void handler_stat() {
        std::cout << "Handler statistics." << std::endl;
    }
};

int main() {
    // Using the functionalities directly in the main function
    m_handler::handler_start();

    m_base_test::base_test();
    m_dev_test::dev_test();
    m_mem_test::mem_test();
    m_knl_test::knl_test();

    m_handler::handler_end();
    m_handler::handler_stat();

    return 0;
}