program test_program
    implicit none
    integer :: a(4)
    logical :: test_passed

    ! Initialize array
    a = (/1, 2, 3, 4/)
    
    ! Manipulate array
    call manipulateArray(a)
    
    ! Test the array
    test_passed = all(a == (/1, 3, 3, 5/))
    if (test_passed) then
        print *, "Fortran Test Passed"
    else
        print *, "Fortran Test Failed"
    end if
end program test_program

subroutine manipulateArray(a)
    integer, intent(inout) :: a(4)
    integer :: i
    
    ! Perform some manipulation on the array
    do i = 2, 4, 2
        a(i) = a(i) + 1
    end do
end subroutine manipulateArray