program DRB125_single_orig_no
    use omp_lib
    implicit none

    integer :: init, local

    !$omp parallel shared(init) private(local)
        !$omp single
        init = 10
        !$omp end single
        local = init
    !$omp end parallel
end program
