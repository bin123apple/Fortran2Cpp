program DRB120_barrier_orig_no
    use omp_lib
    implicit none

    integer :: var

    !$omp parallel shared(var)
    !$omp single
    var = var + 1;
    !$omp end single
    !$omp barrier

    !$omp single
    var = var + 1;
    !$omp end single
    !$omp end parallel

    print 100, var
    100 format ('var =',i3)
end program
