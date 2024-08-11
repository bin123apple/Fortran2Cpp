module m
    implicit none
    intrinsic :: min
    intrinsic :: abs
end module m

program test_main
    use m
    implicit none
    integer :: X, Y

    ! Test 1: min function
    X = 1
    Y = -1
    Y = min(X, 4)
    if (Y /= 1) then
        print *, "Test 1 failed: min(X, 4) did not return 1"
    else
        print *, "Test 1 passed"
    end if

    ! Test 2: abs function
    Y = -3
    Y = abs(Y)
    if (Y /= 3) then
        print *, "Test 2 failed: abs(-3) did not return 3"
    else
        print *, "Test 2 passed"
    end if
end program test_main