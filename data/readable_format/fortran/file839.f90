program test_deallocate
    implicit none
    integer, allocatable :: A, B(:)
    integer :: stat
    character(len=200) :: str
    logical :: test_passed

    ! Test 1: Attempt to deallocate an unallocated scalar
    str = repeat('X', len(str))
    test_passed = .true.
    deallocate(A, stat=stat, errmsg=str)
    if (stat /= 0 .and. str == "Attempt to deallocate an unallocated object") then
        print *, "Test 1 Passed"
    else
        print *, "Test 1 Failed"
        test_passed = .false.
    end if

    ! Test 2: Deallocate an allocated array
    allocate(B(5), stat=stat)
    if (stat /= 0) then
        print *, "Allocation failed, cannot proceed with Test 2"
        stop
    end if
    str = repeat('Y', len(str))
    deallocate(B, stat=stat, errmsg=str)
    if (stat == 0) then
        print *, "Test 2 Passed"
    else
        print *, "Test 2 Failed"
        test_passed = .false.
    end if

    if (test_passed) then
        print *, "All tests passed."
    else
        print *, "Some tests failed."
    end if

end program test_deallocate