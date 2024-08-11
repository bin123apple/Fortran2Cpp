PROGRAM subarray_test
    implicit none
    character(len=7) :: str = 'abcdefg'
    integer :: i
    character(len=3) :: expected1 = 'bcd'
    character(len=3) :: expected2 = 'abc'
    character(len=3) :: expected3 = 'efg'

    ! Test 1: str(2:4)
    if (str(2:4) == expected1) then
        print *, 'Test 1 Passed'
    else
        print *, 'Test 1 Failed'
    end if

    ! Test 2: str(:3)
    if (str(:3) == expected2) then
        print *, 'Test 2 Passed'
    else
        print *, 'Test 2 Failed'
    end if

    ! Test 3: str(5:)
    if (str(5:) == expected3) then
        print *, 'Test 3 Passed'
    else
        print *, 'Test 3 Failed'
    end if

END PROGRAM subarray_test