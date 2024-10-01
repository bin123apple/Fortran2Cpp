#include <iostream>
#define DATA_TYPE int
#define DATA_PRINTF_MODIFIER "%d"
void print_array(int nx, int ny, DATA_TYPE s[], DATA_TYPE q[]) {
 for(int i=0; i<ny; i++) {
 printf(DATA_PRINTF_MODIFIER, s[i]);
 if(i%80 == 0) printf("\n");
 }

 for(int i=0; i<nx; i++) {
 printf(DATA_PRINTF_MODIFIER, q[i]);
 if(i%80 == 0) printf("\n");
 }

 printf("\n");
}
