program DRB070_simd1_orig_no
    use omp_lib
    implicit none

    integer :: len, i
    integer, dimension(:), allocatable :: a, b, c
    len = 100
    allocate (a(len))
    allocate (b(len))
    allocate (c(len))

    !$omp simd
    do i = 1, len
        a(i) = b(i) + c(i)
    end do
    !$omp end simd

    deallocate(a,b,c)
end program
