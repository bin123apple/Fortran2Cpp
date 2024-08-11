! sum.f90
program test_add_integers
    implicit none
    integer :: a, b, result

    ! Example values for a and b
    a = 5
    b = 10

    call add_integers(a, b, result)

    print *, "The result of adding ", a, " and ", b, " is ", result

contains

    subroutine add_integers(a, b, result)
        implicit none
        integer, intent(in) :: a, b
        integer, intent(out) :: result

        result = a + b
    end subroutine add_integers

end program test_add_integers