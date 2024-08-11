#include <cmath>

int numroc(int N, int NB, int IPROC, int ISRCPROC, int NPROCS) {
    int MYDIST = (NPROCS + IPROC - ISRCPROC) % NPROCS;
    int NBLOCKS = N / NB;
    int NUMROC = (NBLOCKS / NPROCS) * NB;
    int EXTRABLKS = NBLOCKS % NPROCS;

    if (MYDIST < EXTRABLKS) {
        NUMROC += NB;
    } else if (MYDIST == EXTRABLKS) {
        NUMROC += N % NB;
    }

    return NUMROC;
}