program test_args_loc
    implicit none
    character(len=6), dimension(3) :: testArray  ! Specify length as 6
    integer :: result

    ! Fill the array
    testArray = ['apple ', 'banana', 'cherry']  ! Ensure each string has the same length

    ! Test 1: Element is in the array
    result = args_loc(testArray, 3, 'banana')
    print *, 'Test 1 (Found): ', result == 2

    ! Test 2: Element is not in the array
    result = args_loc(testArray, 3, 'orange')
    print *, 'Test 2 (Not Found): ', result == 0

    ! Since Fortran doesn't directly support the concept of an "empty" array in the same way as dynamic languages,
    ! demonstrating an empty array test in this context isn't straightforward and may not be applicable.

contains

    integer function args_loc(array, n, elt)
        integer, intent(in) :: n
        character(len=*), intent(in) :: elt
        character(len=6), intent(in) :: array(n)  ! Match the declared length above
        
        integer :: i
        
        do i = 1, n
            if (trim(array(i)) == elt) then
                args_loc = i
                return
            endif
        end do
        args_loc = 0
    end function args_loc

end program test_args_loc