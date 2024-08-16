program DRB085_threadprivate_orig_no
    use omp_lib
    use DRB085
    implicit none

    integer :: len
    integer (kind=8) :: i, sum
    len = 1000
    sum = 0

    !$omp parallel copyin(sum0)
        !$omp do
        do i = 1, len
            call foo(i)
        end do
        !$omp end do
        !$omp critical
        sum = sum+sum0
        !$omp end critical
    !$omp end parallel

    do i = 1, len
        sum1=sum1+i
    end do

    print*,'sum = ',sum,'sum1 =',sum1
end program
