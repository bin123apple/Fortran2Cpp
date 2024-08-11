program test_xclib_utils_and_para
    ! Declare the constants and variables directly in the program
    ! instead of using a separate module.
    integer, parameter :: MPI_COMM_WORLD = 0
    integer, parameter :: MPI_COMM_NULL = -1
    integer, parameter :: MPI_COMM_SELF = -2
    integer, parameter :: stdout = 6
    logical :: nowarning = .FALSE.

    ! Your main program starts here
    ! For demonstration, let's print the values as a simple test.
    print *, 'Testing constants and variables:'
    print *, 'MPI_COMM_WORLD:', MPI_COMM_WORLD
    print *, 'MPI_COMM_NULL:', MPI_COMM_NULL
    print *, 'MPI_COMM_SELF:', MPI_COMM_SELF
    print *, 'stdout:', stdout
    if (nowarning) then
        print *, 'nowarning is TRUE.'
    else
        print *, 'nowarning is FALSE.'
    endif

    ! Add your program's logic here

end program test_xclib_utils_and_para