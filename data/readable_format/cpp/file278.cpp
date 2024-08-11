int f() {
    static int g; // static ensures the value of g is preserved between calls
    g = 42; // Assigning the value
    return g;
}