program DRB013_nowait_orig_yes
    use omp_lib
    implicit none

    integer i, error, len, b
    integer, dimension (:), allocatable :: a

    b = 5
    len = 1000

    allocate (a(len))

    do i = 1, len
        a(i) = i
    end do

    !$omp parallel shared(b, error)
        !$omp parallel
            !$omp do
            do i = 1, len
                a(i) = b + a(i)*5
            end do
            !$omp end do nowait
            !$omp single
            error = a(10) + 1;
            !$omp end single
        !$omp end parallel
    !$omp end parallel

    print*,"error =",error

    deallocate(a)
end program
