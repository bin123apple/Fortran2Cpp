! Define the subroutines first
subroutine fun_task(x, y)
    implicit none
    integer :: x
    integer, dimension(10) :: y

    x = x + 1
    y(1) = y(1) + 1
end subroutine fun_task

subroutine fun_task_2(x, y)
    implicit none
    integer :: x
    integer, dimension(10) :: y

    IF (x /= 42) THEN
        STOP 1
    END IF

    IF (y(1) /= 10042) THEN
        STOP 2
    END IF
end subroutine fun_task_2

! Main program starts here
program main
    implicit none
    integer :: i
    integer, dimension(10) :: j

    ! Initialize variables
    i = 41
    j = 10041

    ! Call the subroutines
    call fun_task(i, j)
    call fun_task_2(i, j)

    ! Check results (for testing purposes)
    print *, "i:", i
    print *, "j(1):", j(1)

    ! Assuming you want some basic check here as well
    if (i == 42 .and. j(1) == 10042) then
        print *, "All tests passed."
    else
        print *, "Tests failed."
    end if
end program main