#include <iostream>
#define DATA_TYPE int
#define DATA_PRINTF_MODIFIER "%d"
using namespace std;
void print_array(DATA_TYPE y[], int ny)
{
    for(int i = 0; i < ny; i++)
    {
        printf(DATA_PRINTF_MODIFIER, y[i]);
        if (i % 20 == 0)
           cout << endl;
    }
    cout << endl;
}
