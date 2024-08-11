#include <cstddef> // For size_t

void movec(size_t n, const char* source, char* dest) {
    for(size_t i = 0; i < n; ++i) {
        dest[i] = source[i];
    }
}