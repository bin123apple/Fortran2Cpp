program DRB121_reduction_orig_no
    use omp_lib
    implicit none

    integer :: var, i, sum1, sum2

    var = 0
    sum1 = 0
    sum2 = 0

    !$omp parallel reduction(+: var)
        !$omp do schedule(static) reduction(+: sum1)
        do i = 1, 5
            sum1 = sum1+i
        end do
        !$omp end do

        !$omp do schedule(static) reduction(+: sum2)
        do i = 1, 5
            sum2 = sum2+i
        end do
        !$omp end do

        var = sum1 + sum2
    !$omp end parallel

    print 100, var
    100 format ('var =',3i8)
end program
