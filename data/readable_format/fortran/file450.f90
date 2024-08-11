module data_mod
    implicit none
contains
    function addTwoNumbers(a, b) result(c)
        implicit none
        integer, intent(in) :: a, b
        integer :: c

        c = a + b
    end function addTwoNumbers
end module data_mod

program test_data_mod
    use data_mod
    implicit none
    integer :: result

    ! Test the addTwoNumbers function
    result = addTwoNumbers(2, 3)
    if (result == 5) then
        print *, "Test passed. 2 + 3 = ", result
    else
        print *, "Test failed."
    endif
end program test_data_mod