program p1_test
    implicit none
    integer, parameter  :: i1    = kind(0)
    integer, parameter  :: i2(1) = [i1]
    integer(kind=i2(1)) :: i3

    i3 = int(0, i1)
    if (i3 /= 0) then
        print *, "Test 1 Failed"
        stop
    else
        print *, "Test 1 Passed"
    end if

    i3 = int(0, i2(1))
    if (i3 /= 0) then
        print *, "Test 2 Failed"
        stop
    else
        print *, "Test 2 Passed"
    end if
end program p1_test