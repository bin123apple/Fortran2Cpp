#include <cstdlib> // For std::abort

int main() {
    int i;
    bool l;

    l = false;
    i = -1;
    if (l) if (i) goto label999; else goto label999; else goto label999;

    l = true;
    if (l) if (i) goto label10; else goto label999; else goto label999;
    goto label999;

label10:
    i = 0;
    if (l) if (i) goto label999; else goto label20; else goto label999;
    goto label999;

label20:
    i = 1;
    if (l) if (i) goto label999; else goto label999; else goto label30;
    goto label999;

label999:
    std::abort(); // or you could use exit(EXIT_FAILURE);
    return 0; // This line will never be reached because of std::abort

label30:
    return 0;
}