program DRB114_if_orig_yes
    use omp_lib
    implicit none

    integer i, len, rem, j
    real :: u
    integer, parameter :: dp = kind(1.0d0)
    real(dp), dimension(:), allocatable :: a

    len = 100
    allocate (a(len))

    do i = 1, len
        a(i) = i
    end do

    call random_number(u)
    j = FLOOR(100*u)

    !$omp parallel do if (MOD(j,2)==0)
    do i = 1, len-1
        a(i+1) = a(i)+1
    end do
    !$omp end parallel do

    print*,'a(50) =',a(50)

    deallocate(a)
end program
