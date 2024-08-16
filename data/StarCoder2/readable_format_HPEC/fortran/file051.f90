program DRB137_simdsafelen_orig_no
    use omp_lib
    implicit none

    integer :: i, m, n
    real :: b(4)

    m = 1
    n = 4

    !$omp simd safelen(2)
    do i = m+1, n
        b(i) = b(i-m) - 1.0
    end do

    print*, b(3)
end program
