program DRB090_static_local_orig_yes
    use omp_lib
    implicit none

    integer :: i, len
    integer, dimension(:), allocatable :: a, b
    integer, save :: tmp
    integer :: tmp2

    len = 100
    allocate (a(len))
    allocate (b(len))

    do i = 1, len
        a(i) = i
        b(i) = i
    end do

    !$omp parallel
        !$omp do
        do i = 1, len
            tmp = a(i)+i
            a(i) = tmp
        end do
        !$omp end do
    !$omp end parallel

    !$omp parallel
        !$omp do
        do i = 1, len
            tmp2 = b(i)+i
            b(i) = tmp2
        end do
        !$omp end do
    !$omp end parallel

    print 100, a(50), b(50)
    100 format (i3,3x,i3)

    deallocate(a,b)

end program
