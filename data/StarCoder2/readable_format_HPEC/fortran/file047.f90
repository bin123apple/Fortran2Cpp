program DRB124_master_orig_yes
    use omp_lib
    implicit none

    integer :: init, local

    !$omp parallel shared(init) private(local)
        !$omp master
        init = 10
        !$omp end master
        local = init
    !$omp end parallel

end program
