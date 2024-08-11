program test_gtabs_int
    implicit none
    logical :: result

    result = gtabs_int(3, -4)
    print *, "Test 1 (3, -4): ", result  ! Expected: .false.

    result = gtabs_int(-5, 2)
    print *, "Test 2 (-5, 2): ", result  ! Expected: .true.

    result = gtabs_int(-2, -3)
    print *, "Test 3 (-2, -3): ", result  ! Expected: .false.

    result = gtabs_int(0, 0)
    print *, "Test 4 (0, 0): ", result    ! Expected: .false.
contains
    function gtabs_int(x,y) result (ordered)
    integer, intent(in) :: x
    integer, intent(in) :: y
    logical :: ordered
    if (abs(real(x)) > abs(real(y))) then
        ordered = .true.
    else
        ordered = .false.
    end if
    end function gtabs_int
end program test_gtabs_int