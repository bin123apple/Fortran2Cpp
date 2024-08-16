program DRB066_pointernoaliasing_orig_no
    use omp_lib
    use DRB066
    implicit none

    integer :: N
    N = 1000

    call setup(N)

end program
