#include <iostream>
#include <cstdlib>
#include <omp.h>

int main(int argc, char* argv[]) {
  int len = 100;
  if(argc > 1){
    len = atoi(argv[1]);
    if(len <= 0){
      std::cout<<"Error, invalid integer value.\n";
      return 1;
    }
  } else {
    std::cout<<"No command line arguments provided.\n";
  }

  int* a = new int[len];

  for (int i = 0; i < len; i++){
    a[i] = i+1;
  }

#pragma omp parallel for
  for (int i = 0; i < len-1; i++){
    a[i+1] = a[i]+1;
  }

  std::cout<<"a[50]="<<a[49]<<std::endl;
  delete[] a;
  return 0;
}
