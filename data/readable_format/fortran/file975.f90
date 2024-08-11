module mymath
    implicit none
    contains
    function Lagrange(x, y, z, n) result(fn)
        real, intent(in) :: x(:), y(:), z
        integer, intent(in) :: n
        real :: fn
        integer :: i, j
        real :: prod

        fn = 0.0
        do i = 1, n
            prod = 1.0
            do j = 1, n    
                if (j == i) then
                    cycle
                end if
                prod = prod * ((z - x(j)) / (x(i) - x(j)))
            end do
            fn = fn + prod * y(i)
        end do
    end function Lagrange
end module mymath

program test_lagrange
    use mymath
    implicit none
    
    real, dimension(3) :: x = [1.0, 2.0, 3.0]
    real, dimension(3) :: y = [2.0, 4.0, 6.0]
    real :: z
    real :: expected, result
    integer :: n

    n = 3

    ! Test case 1
    z = 2.5
    expected = 5.0
    result = Lagrange(x, y, z, n)
    call assert_approx_equal(result, expected, 1.0e-5)

    ! Test case 2
    z = 1.0
    expected = 2.0
    result = Lagrange(x, y, z, n)
    call assert_approx_equal(result, expected, 1.0e-5)

    ! Test case 3
    z = 3.0
    expected = 6.0
    result = Lagrange(x, y, z, n)
    call assert_approx_equal(result, expected, 1.0e-5)

    print *, "All Fortran tests passed."

contains

    subroutine assert_approx_equal(value1, value2, tol)
        real, intent(in) :: value1, value2, tol
        if (abs(value1 - value2) > tol) then
            print *, "Test failed: ", value1, " != ", value2
            stop
        end if
    end subroutine assert_approx_equal
end program test_lagrange