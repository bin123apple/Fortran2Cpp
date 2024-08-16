#include <stdio.h>
#include <omp.h>

int a[100];
void gen_task(int i);

int main()
{
    int i;

#pragma omp parallel
 {
#pragma omp single
  {
   for(i=0; i<100; i++)
    gen_task(i);
  }
 }

 for(i=0; i<100; i++)
  if(a[i]!=(i+1))
   printf("warning: a[%d] = %d not expected %d
",i,a[i],i+1);
 return 0;
}

void gen_task(int i)
{
#pragma omp task
 a[i]=i+1;
}
