PROGRAM subarray_test

    implicit none
    character(len=7) :: str
    integer :: array(7)
    integer :: i
    logical :: test_passed

    str = 'abcdefg'
    do i = 1, 7
        array(i) = i
    end do

    ! Testing array initialization
    test_passed = .TRUE.
    do i = 1, 7
        if (array(i) /= i) then
            test_passed = .FALSE.
            exit
        endif
    end do
    if (test_passed) then
        print *, "Array initialization test passed."
    else
        print *, "Array initialization test failed."
    endif

    ! Testing string slicing
    if (str(2:4) == 'bcd') then
        print *, "Slice 2:4 test passed."
    else
        print *, "Slice 2:4 test failed."
    endif

    if (str(:3) == 'abc') then
        print *, "Slice :3 test passed."
    else
        print *, "Slice :3 test failed."
    endif

    if (str(5:) == 'efg') then
        print *, "Slice 5: test passed."
    else
        print *, "Slice 5: test failed."
    endif

    if (str(:) == 'abcdefg') then
        print *, "Full string slice test passed."
    else
        print *, "Full string slice test failed."
    endif

END PROGRAM subarray_test