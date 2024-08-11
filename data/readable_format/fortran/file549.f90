PROGRAM p1

    ! Declaration of variables
    integer :: x = 1, y = 2, z

    ! Perform the addition
    z = x + y
    
    ! Output the result
    print *, "The result of x + y is: ", z

    ! Test the result
    if (z == 3) then
        print *, "Test passed."
    else
        print *, "Test failed."
    endif

END PROGRAM p1