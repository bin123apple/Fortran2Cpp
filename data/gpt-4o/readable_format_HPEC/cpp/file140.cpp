#include <iostream>
#include <omp.h>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[]){
    int len = 2000;
    int uLen;
    if(argc == 1){
        cerr << "No command line arguments provided." << endl;
        exit(EXIT_FAILURE);
    } else {
        len = atoi(argv[1]);
    }
    int *a = new int[len];
    for(int i = 0; i < len; i++)
        a[i] = i;
    uLen = len/2;

#pragma omp parallel for
    for(int i = 0; i < uLen; i++)
        a[2*i] = a[i] + 1;
    delete[] a;
    return 0;
}
