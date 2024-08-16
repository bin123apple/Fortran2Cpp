program DRB076_flush_orig_no
    use omp_lib
    use DRB076
    implicit none

    integer :: i, sum
    i = 0
    sum = 0

    !$omp parallel reduction(+:sum) num_threads(10) private(i)
    call f1(i)
    sum = sum + i
    !$omp end parallel

    if (sum /= 10) then
        print*,'sum =',sum
    end if
end program
