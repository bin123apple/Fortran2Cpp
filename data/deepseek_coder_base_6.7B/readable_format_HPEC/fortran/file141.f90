program DRB091_threadprivate2_orig_no
    use omp_lib
    use DRB091
    implicit none

    integer :: len, i, sum
    len = 1000
    sum = 0

    !$omp parallel copyin(sum0)
        !$omp do
        do i = 1, len
            sum0 = sum0+i
        end do
        !$omp end do
        !$omp critical
        sum = sum+sum0
        !$omp end critical
    !$omp end parallel

    do i = 1, len
        sum1 = sum1+i
    end do

    print*,'sum =',sum,'sum1 =',sum1

end program
