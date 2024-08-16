program DRB024_simdtruedep_orig_yes
    use omp_lib
    implicit none

    integer :: i, len
    integer, dimension(:), allocatable :: a
    integer, dimension(:), allocatable :: b

    len = 100

    allocate (a(len))
    allocate (b(len))

    do i = 1, len
        a(i) = i
        b(i) = i+1
    end do

    !$omp simd
    do i = 1, len-1
        a(i+1) = a(i) + b(i)
    end do

    do i = 1, len
        write(6,*) 'Values for i and a(i) are:', i, a(i)
    end do

    deallocate(a,b)
end program
