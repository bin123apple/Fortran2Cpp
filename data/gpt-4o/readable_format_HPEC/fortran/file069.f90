program DRB035_truedepscalar_orig_yes
    use omp_lib
    implicit none

    integer i, tmp, len
    integer, dimension(:), allocatable :: a

    len = 100
    tmp = 10
    allocate (a(len))

    !$omp parallel do
    do i = 1, len
        a(i) = tmp
        tmp = a(i) + i
    end do
    !$omp end parallel do

    print 100, a(50)
    100 format ('a(50) =',i3)

    deallocate(a)
end program
