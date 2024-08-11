module math_operations
    implicit none
contains
    real function asum(a, n, a0)
        real, dimension(:), intent(in) :: a
        integer, intent(in) :: n
        real, intent(in) :: a0
        integer :: i

        asum = a0
        do i = 1, n
            asum = asum + a(i)
        end do
    end function asum
end module math_operations

program testAsum
    use math_operations
    implicit none
    real :: a(8)
    real :: result
    integer :: i

    ! Fill the array
    do i = 1, 8
        a(i) = i
    end do

    ! Test the asum function
    result = asum(a, 8, 0.0)
    if (result == 36.0) then
        print *, "Test PASS"
    else
        print *, "Test FAIL: Expected 36.0, got ", result
    end if
end program testAsum