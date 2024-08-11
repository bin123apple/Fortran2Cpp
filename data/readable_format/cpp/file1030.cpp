#include <iostream>
using namespace std;

namespace othermod {
    
    void othersub() {
        // Implementation of othersub
        cout << "othersub called" << endl;
    }

}

namespace testmod {

    class t1 {
    public:
        void proc1() {
            // Implementation of proc1
            cout << "proc1 called" << endl;
        }

        float proc2(float x) {
            cout << "proc2 called with x = " << x << endl;
            return x / 2;
        }
    };

    class t2 {
    public:
        int x;

        int proc3() {
            cout << "proc3 called" << endl;
            return 42;
        }

    private:
        void othersub() {
            // Direct call to othermod's othersub as a private method
            ::othermod::othersub();
        }
    };

    class t3 {
        // Empty class, as per original Fortran type
    };

    class t4 {
    private:
        // Empty class with a private section, as per original Fortran type
    };
}

int main() {
    testmod::t1 obj1;
    testmod::t2 obj2;
    
    obj1.proc1(); // Testing proc1
    float result2 = obj1.proc2(4.0); // Testing proc2
    cout << "Result of proc2: " << result2 << endl;
    
    int result3 = obj2.proc3(); // Testing proc3
    cout << "Result of proc3: " << result3 << endl;

    return 0;
}