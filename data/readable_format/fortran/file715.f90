program simple_example
    implicit none
    integer :: rank, mpi_size, ierror

    ! Simulating MPI Initialization
    call start_parallel(rank, mpi_size, ierror)
    print *, "Process Rank: ", rank
    print *, "Total Number of Processes: ", mpi_size
    ! Simulating MPI Finalization
    call end_parallel(ierror)

contains

    subroutine start_parallel(rank, mpi_size, ierror)
        integer, intent(out) :: rank, mpi_size, ierror

        ! Simulating getting rank and size
        rank = 0 ! In a non-MPI context, there's only one process.
        mpi_size = 1 ! Only one process is available.
        ierror = 0 ! No error.
    end subroutine start_parallel

    subroutine end_parallel(ierror)
        integer, intent(out) :: ierror

        ! Simulating MPI finalization
        ierror = 0 ! No error.
    end subroutine end_parallel

end program simple_example