module math_operations
    implicit none
contains
    function add(a, b) result(c)
        integer, intent(in) :: a, b
        integer :: c
        c = a + b
    end function add
end module math_operations

program test_add
    use math_operations
    implicit none
    integer :: result

    result = add(5, 3)

    if (result == 8) then
        print *, 'Test passed.'
    else
        print *, 'Test failed.'
    end if
end program test_add