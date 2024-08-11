module funcs
    implicit none
contains
    function assumed_len(x) result(res)
        character(len=:), allocatable :: res
        integer, intent(in) :: x
        res = repeat(' ', x)  ! Creates a string with x spaces.
    end function assumed_len
end module funcs

program test_funcs
    use funcs
    implicit none
    character(:), allocatable :: result
    integer :: x

    ! Test the assumed_len function
    x = 5
    result = assumed_len(x)
    if (len(trim(result)) == x) then
        print *, "Test passed: length matches expected."
    else
        print *, "Test failed: length does not match expected."
    end if

    ! Add more tests as needed

end program test_funcs