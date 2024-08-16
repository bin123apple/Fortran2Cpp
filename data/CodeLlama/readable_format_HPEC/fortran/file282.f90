program DRB084_threadprivatemissing_orig_yes
    use omp_lib
    use DRB084
    implicit none

    integer (kind=8) :: i, sum
    sum = 0

    !$omp parallel
        !$omp do
            do i = 1, 1001
                call foo(i)
            end do
        !$omp end do
        !$omp critical
            sum = sum + sum0
        !$omp end critical
    !$omp end parallel

    do i = 1, 1001
        sum1 = sum1+i
    end do

    print*,'sum = ',sum,'sum1 =',sum1
end program
