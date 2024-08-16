program DRB115_forsimd_orig_yes
    use omp_lib
    implicit none

    integer i, len
    integer, dimension(:), allocatable :: a,b

    len = 100
    allocate (a(len))
    allocate (b(len))

    do i = 1, len
        a(i) = i
        b(i) = i+1
    end do

    !$omp simd
    do i = 1, len-1
        a(i+1)=a(i)+b(i)
    end do

    print*,'a(50) =',a(50)

    deallocate(a,b)
end program
