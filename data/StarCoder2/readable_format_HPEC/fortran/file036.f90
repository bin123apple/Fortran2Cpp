program DRB092_threadprivatemissing2_orig_yes
    use omp_lib
    use DRB092
    implicit none

    integer :: i, sum
    sum = 0
    sum0 = 0
    sum1 = 0

    !$omp parallel
        !$omp do
        do i = 1, 1001
            sum0 = sum0+i
        end do
        !$omp end do
        !$omp critical
        sum = sum+sum0
        !$omp end critical
    !$omp end parallel

    do i = 1, 1001
        sum1=sum1+i
    end do

    print*,'sum =',sum,'sum1 =',sum1

end program
