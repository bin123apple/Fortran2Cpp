module mTypes
    integer, parameter :: rb = 8
    integer, parameter :: sl = 128
end module mTypes

program testMTypes
    use mTypes
    implicit none

    if (rb == 8) then
        print *, 'Test rb PASS'
    else
        print *, 'Test rb FAIL'
    end if

    if (sl == 128) then
        print *, 'Test sl PASS'
    else
        print *, 'Test sl FAIL'
    end if
end program testMTypes