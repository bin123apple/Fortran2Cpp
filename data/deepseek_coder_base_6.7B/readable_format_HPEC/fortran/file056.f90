program DRB141_reduction_barrier_orig_no
    use omp_lib
    implicit none

    integer :: a, i

    !$omp parallel shared(a) private(i)
        !$omp master
        a = 0
        !$omp end master
        
        !$omp barrier        

        !$omp do reduction(+:a)
        do i = 1, 10
            a = a+i
        end do
        !$omp end do

        !$omp single
        print*, "Sum is ", A
        !$omp end single

    !$omp end parallel
end program
