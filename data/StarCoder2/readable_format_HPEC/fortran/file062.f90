program DRB135_taskdep_mutexinoutset_orig_no_omp50
    use omp_lib
    implicit none

    integer :: a, b, c, d

    !$omp parallel
    !$omp single
        !$omp task depend(out: c)
        c = 1      ! Task T1
        !$omp end task
        !$omp task depend(out: a)
        a = 2      ! Task T2
        !$omp end task
        !$omp task depend(out: b)
        b = 3      ! Task T3
        !$omp end task
        !$omp task depend(in: a)
        c = c + a  ! Task T4
        !$omp end task
        !$omp task depend(in: b) 
        c = c + b  ! Task T5
        !$omp end task
        !$omp task depend(in: c)
        d = c      ! Task T6
        !$omp end task
    !$omp end single
    !$omp end parallel

    print *, d
end program
