program main
    implicit none
    ! Test variables
    double precision :: x, result

    ! Initialize parameters
    call quadratic_set(1.0d0, -3.0d0, 2.0d0)  ! a=1, b=-3, c=2, roots are x=1 and x=2
    x = 1.0d0

    ! Calculate result
    result = quadratic(x)

    ! Check the result
    if (result == 0.0d0) then
        print *, "Test passed: quadratic(1) = 0"
    else
        print *, "Test failed: quadratic(1) != 0, result = ", result
    end if

contains

    subroutine quadratic_set(new_a, new_b, new_c)
        implicit none
        double precision, intent(in) :: new_a, new_b, new_c
        double precision :: a, b, c

        a = new_a
        b = new_b
        c = new_c
    end subroutine quadratic_set

    function quadratic(x) result(quadratic_result)
        implicit none
        double precision, intent(in) :: x
        double precision :: quadratic_result
        double precision :: a, b, c

        quadratic_result = a*x**2 + b*x + c
    end function quadratic

end program main