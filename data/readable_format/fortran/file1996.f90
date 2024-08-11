! test_subr.f90
program test_subr
    implicit none
    real :: a(50)
    integer :: i
    logical :: test_passed

    ! Initialize array with distinct values to track changes
    do i = 1, 50
        a(i) = i
    end do

    call subr(a)

    ! Assuming the subroutine sets all values to 0
    test_passed = .true.
    do i = 1, 50
        if (a(i) /= 0) then
            write(*,*) "Test failed at index:", i, "Value:", a(i)
            test_passed = .false.
            exit
        endif
    end do

    if (test_passed) then
        write(*,*) "All tests passed."
    endif

contains

    subroutine subr(a)
        real, intent(inout) :: a(50)
        a = 0
    end subroutine subr

end program test_subr