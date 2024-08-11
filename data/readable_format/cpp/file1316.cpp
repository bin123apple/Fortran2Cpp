// file: main.cpp
#include <iostream>

class Handlers {
public:
    static void onClosing() {
        std::cout << "Closing event triggered." << std::endl;
    }
};

int main() {
    Handlers::onClosing();
    return 0;
}