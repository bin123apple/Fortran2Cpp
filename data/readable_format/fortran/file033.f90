program testEapVarApp
    implicit none

    real :: x, resultF, resultG, resultH

    ! Test values
    x = 2.0

    ! Expected values for f, g, h with x = 2.0
    ! Assuming g(x) = x for simplicity, these are calculated based on the functions' logic
    resultF = 4.0
    resultG = 2.0
    resultH = 4.0

    ! Test function f
    if (f(x) == resultF) then
        print *, "f(x) test passed."
    else
        print *, "f(x) test failed."
    end if

    ! Test function g
    if (g(x) == resultG) then
        print *, "g(x) test passed."
    else
        print *, "g(x) test failed."
    end if

    ! Test function h
    if (h(x) == resultH) then
        print *, "h(x) test passed."
    else
        print *, "h(x) test failed."
    end if

contains

    function f(x)
        real :: x
        real :: f
        real :: j, k, l
        j = x
        k = g(j*j)
        l = j * g(j * j * j)
        f = k
    end function f

    function g(x)
        real :: x
        real :: g
        g = x
    end function g

    function h(x)
        real :: x
        real :: h
        h = f(x)
    end function h

end program testEapVarApp