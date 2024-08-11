module functions
contains
    function fdot(a, b, n)
        real, dimension(:), intent(in) :: a, b
        integer, intent(in) :: n
        real :: fdot
        integer :: i

        fdot = 0.0
        do i = 1, n
            fdot = fdot + a(i) * b(i)
        end do
    end function fdot
end module functions

program test_fdot
    use functions
    implicit none
    real :: result
    real, dimension(3) :: a = (/1.0, 2.0, 3.0/)
    real, dimension(3) :: b = (/4.0, 5.0, 6.0/)
    integer :: n = 3

    result = fdot(a, b, n)
    print *, 'Dot product: ', result
end program test_fdot