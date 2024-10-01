#include <stdio.h>
#include <omp.h>
class A {
public:
    static int counter;
    static int pcounter;
    A(int a, int b) { counter=a; pcounter=b; }
};
int A::counter = 0;
int A::pcounter = 0;
int main()
{
#pragma omp parallel
{
    A::counter=A::counter+1;
    A::pcounter=A::pcounter+1;
}
printf("%d %d\n", A::counter, A::pcounter);
return 0;
}
