module math_operations
    implicit none
contains
    function add(a, b)
        integer, intent(in) :: a, b
        integer :: add

        add = a + b
    end function add
end module math_operations

program test_addition
    use math_operations
    implicit none
    integer :: result

    result = add(5, 3)
    if (result == 8) then
        print *, "Fortran Test passed."
    else
        print *, "Fortran Test failed."
    endif
end program test_addition