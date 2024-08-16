#include <stdio.h>
#include <fstream>
#include <omp.h>
int main()
{
 int a[1000];
 int i;
 for (i=0; i<1000; i++)
 a[i] = i+1;
 std::ofstream file;
 file.open("mytempfile.txt", std::ios_base::app);
#pragma omp parallel for
 for (i=0; i<1000; i++)
 file << a[i] << "
";
 file.close();
 return 0;
}
