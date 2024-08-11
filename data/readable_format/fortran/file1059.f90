program testBar
    implicit none
    integer :: result

    ! Test 1
    result = bar(5, 3)
    if (result == 8) then
        print *, 'Test 1 Passed.'
    else
        print *, 'Test 1 Failed.'
    endif

    ! Test 2
    result = bar(-1, -1)
    if (result == -2) then
        print *, 'Test 2 Passed.'
    else
        print *, 'Test 2 Failed.'
    endif

    ! Test 3
    result = bar(0, 0)
    if (result == 0) then
        print *, 'Test 3 Passed.'
    else
        print *, 'Test 3 Failed.'
    endif

contains

    integer function bar(a, b)
        integer, intent(in) :: a, b
        bar = a + b
    end function bar
    
end program testBar