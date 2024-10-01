#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char **argv){
    int i, N;
    int *a;
    N = 100;

    if(argc==1){
        printf("No command line arguments provided.\n");
        return 1;
    }

    N = atoi(argv[1]);

    a = (int*)malloc(N* sizeof(int));
    if(a==NULL){
        printf("Allocation error, program terminated.\n");
        exit(1);
    }

    if(N>=1){
        N = atoi(argv[1]);
        if(N == 0){
            printf("Error, invalid integer value.\n");
            return 1;
        }
    }

    #pragma omp parallel for shared(a)
    for(i=0; i<N; i++){
        a[i] = i+1;
        if(N > 10000) a[0] = 1;
    }
    free(a);

    return 0;
}
