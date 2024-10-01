#include <iostream>
#define DATA_TYPE double
#define DATA_PRINTF_MODIFIER "%f\n"

void print_array(int n, DATA_TYPE* x1, DATA_TYPE* x2)
{
    for (int i = 0; i < n; i++)
    {
        printf(DATA_PRINTF_MODIFIER, x1[i]);
        printf(DATA_PRINTF_MODIFIER, x2[i]);
        if (i % 20 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
}
