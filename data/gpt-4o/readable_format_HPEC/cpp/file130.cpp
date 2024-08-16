#include <stdio.h>
#include <omp.h>
int main()
{
 int section_count=0;
 omp_set_dynamic(0);
 omp_set_num_threads(1);
#pragma omp parallel
 {
#pragma omp sections firstprivate(section_count)
 {
#pragma omp section
 {
 section_count = section_count + 1;
 printf ("section_count = %d
", section_count);
 }
#pragma omp section
 {
 section_count = section_count + 1;
 printf ("section_count = %d
", section_count);
 }
 }
 }
 return 0;
}
