program test_builtinfcns
    implicit none
    real :: pi, x, y, epsilon

    ! Test values
    pi = acos(-1.0)
    x = cos(pi)
    y = sqrt(exp(log(pi)))**2
    epsilon = 1.0E-5 ! Tolerance for floating point comparison

    ! Testing pi
    if (abs(pi - 3.1415927) > epsilon) then
        print *, "Test Failed for pi"
    else
        print *, "Test Passed for pi"
    end if

    ! Testing x
    if (abs(x - (-1.0)) > epsilon) then
        print *, "Test Failed for x"
    else
        print *, "Test Passed for x"
    end if

    ! Testing y
    if (abs(y - pi) > epsilon) then
        print *, "Test Failed for y"
    else
        print *, "Test Passed for y"
    end if

end program test_builtinfcns