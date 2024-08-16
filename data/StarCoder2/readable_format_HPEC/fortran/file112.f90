program DRB103_master_orig_no
    use omp_lib
    implicit none

    integer k

    !$omp parallel
    !$omp master
    k = omp_get_num_threads()
    print 100, k
    100 format ('Number of threads requested =',3i8)
    !$omp end master
    !$omp end parallel

end program
