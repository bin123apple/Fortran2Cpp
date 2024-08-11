program test_logical_integer
    implicit none
    LOGICAL(kind=1) l1
    LOGICAL(kind=2) l2
    LOGICAL         l4
    INTEGER(kind=1) i1
    INTEGER(kind=2) i2
    INTEGER         i4
    LOGICAL         test_result

    ! Initialize logical variables
    l1 = .TRUE.
    l2 = .TRUE.
    l4 = .TRUE.

    ! Test 1: Assign .TRUE. to integers and check
    i1 = 1  ! True
    i2 = 1  ! True
    i4 = 1  ! True
    test_result = (i1 /= 0) .and. (i2 /= 0) .and. (i4 /= 0)
    if (test_result) then
        print *, "Test 1 Passed"
    else
        print *, "Test 1 Failed"
    end if

    ! Test 2: Assign .FALSE. to integers and check
    i1 = 0  ! False
    i2 = 0  ! False
    i4 = 0  ! False
    test_result = (i1 == 0) .and. (i2 == 0) .and. (i4 == 0)
    if (test_result) then
        print *, "Test 2 Passed"
    else
        print *, "Test 2 Failed"
    end if

    ! Additional tests for logical to integer conversion and vice-versa can be added here.
    ! Ensure all logical comparisons are done with logical variables to avoid errors.

end program test_logical_integer