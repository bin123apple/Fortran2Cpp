program DRB108_atomic_orig_no
    use omp_lib
    implicit none

    integer a
    a = 0

    !$omp parallel
    !$omp atomic
    a = a+1
    !$omp end atomic
    !$omp end parallel

    print 100, a
    100 format ('a =',3i8)
end program
