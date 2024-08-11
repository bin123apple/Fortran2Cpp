#include <memory>
#include <vector>

class M {
public:
    int a;  // public variable

protected:
    int i;  // protected variable

private:
    int b;  // private variable

public:
    std::vector<int> j;  // equivalent to allocatable, using std::vector for dynamic allocation

    M() : a(0), b(0), i(0) {}  // constructor to initialize variables

    // Additional member functions can be added here if needed
};

int main() {
    M instance;
    instance.a = 5;
    instance.j.push_back(10);

    // instance.b is not accessible here
    // instance.i is not accessible here

    return 0;
}