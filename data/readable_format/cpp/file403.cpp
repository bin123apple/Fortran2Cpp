#include <iostream>
#include <mpi.h>

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int me, nprocs;
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &me);
    
    const int N = 100;
    long long a[N];
    int b[N];
    int nerr = 0;

    // Initialize a
    for (int i = 0; i < N; i++) {
        a[i] = i + me * 100LL;
    }

    // Initialize b
    std::fill_n(b, N, -99);

    MPI_Barrier(MPI_COMM_WORLD); // sync all

    if (me == 0) {
        if (nprocs > 1) { // Ensure there is a second process
            // Receive from process 2 (index 1)
            MPI_Recv(b + 10, 34, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
    } else if (me == 2) { // Process 3 in Fortran is index 2 here
        // Send to process 0
        for (int i = 0, j = 0; i < N; i += 3, j++) {
            b[j + 10] = a[i];
        }
        MPI_Send(b + 10, 34, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Barrier(MPI_COMM_WORLD); // sync all

    // Validation part (a)
    for (int i = 0; i < N; i++) {
        long long nval = i + me * 100LL;
        if (a[i] != nval) {
            std::cout << "a(" << i << ")[" << me << "]=" << a[i] << " should be " << nval << std::endl;
            nerr++;
        }
    }

    // Validation part (b)
    for (int i = 0; i < N; i++) {
        long long nval = -99;
        if ((me == 0 && i >= 10 && i < 44)) {
            nval = a[(i - 10) * 3] + 100;
        } else if (me == 2 && i >= 10 && i < 44) {
            nval = a[(i - 10) * 3];
        }
        if (b[i] != nval) {
            std::cout << "b(" << i << ")[" << me << "]=" << b[i] << " should be " << nval << std::endl;
            nerr++;
        }
    }

    if (nerr == 0) {
        std::cout << "result[" << me << "] OK" << std::endl;
    } else {
        std::cout << "result[" << me << "] number of NGs: " << nerr << std::endl;
    }

    MPI_Finalize();
    return 0;
}