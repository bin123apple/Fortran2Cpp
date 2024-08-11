namespace m {
    class t {
    public:
        // Constructor, destructor, and other member functions can be defined here.
    };
}

class t { // This is in the global namespace, separate from m::t
public:
    // Constructor, destructor, and other member functions can be defined here.
};

// Usage example
int main() {
    m::t object1; // object of class t defined inside namespace m
    ::t object2;  // object of class t defined in the global namespace

    return 0;
}