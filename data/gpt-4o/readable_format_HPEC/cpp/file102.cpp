#include <stdio.h>
#include <stdlib.h>

double base[2025];
int indexSet[] = { 521, 523, 525, 533, 529, 531, 547, 549, 551, 553, 555, 557, 573, 575, 577, 579, 581, 583, 599,
                   601, 603, 605, 607, 609, 625, 627, 629, 631, 633, 635, 651, 653, 655, 657, 659, 661, 859, 861, 
                   /* and so on till 2013 */ 
                   2005, 2007, 2009, 2011, 2013 };

int main()
{
    int i, idx1, idx2;

    for (i = 520; i < 2025; i++)
        base[i] = 0.5 * (i + 1);

#pragma omp parallel for private(idx1, idx2)
    for (i = 0; i < 180; i++)
    {
        idx1 = indexSet[i] - 1;
        idx2 = indexSet[i] + 11;
        base[idx1] = base[idx1] + 1.0;
        base[idx2] = base[idx2] + 3.0;
    }

    printf("xa1[999] = %f, xa2[1285] = %f\n", base[998], base[1284]);

    return 0;
}
