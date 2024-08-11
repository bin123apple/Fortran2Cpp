program test_scasumsub
    implicit none
    
    ! Declarations
    integer :: n, incx
    real :: asum
    complex, allocatable :: x(:)

    ! Initialize variables
    n = 4
    incx = 1
    allocate(x(n))
    x = [(1.0, 2.0), (-3.0, 4.0), (5.0, -6.0), (-7.0, 8.0)]

    ! Call scasumsub
    call scasumsub(n, x, incx, asum)
    
    ! Output the result
    print *, 'ASUM:', asum

contains

    ! scasumsub subroutine
    subroutine scasumsub(n, x, incx, asum)
        integer, intent(in) :: n, incx
        complex, intent(in) :: x(*)
        real, intent(out) :: asum
        integer :: i

        asum = 0.0
        do i = 1, n, incx
            asum = asum + cabs(x(i))
        end do
    end subroutine scasumsub

    ! scasum function (for illustration)
    real function scasum(n, x, incx)
        integer, intent(in) :: n, incx
        complex, intent(in) :: x(*)
        integer :: i

        scasum = 0.0
        do i = 1, n, incx
            scasum = scasum + cabs(x(i))
        end do
    end function scasum

end program test_scasumsub