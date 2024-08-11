program main
    implicit none
    integer :: a(10)
    integer :: result

    a = [2, 1, 4, 6, 3, 2, 6, 3, 3, 1]

    call testMaxValueAndIndex(a, result)
    if (result /= 0) stop "Test for finding max value and index failed."

    call testMinValueAndIndex(a, result)
    if (result /= 0) stop "Test for finding min value and index failed."

    print *, "All tests passed successfully."

contains

    subroutine testMaxValueAndIndex(a, result)
        integer, intent(in) :: a(10)
        integer, intent(out) :: result
        integer :: i, sa, ia

        sa = a(1)
        ia = 1
        do i = 2, 10
            if (sa < a(i)) then
                ia = i
                sa = a(i)
            endif
        enddo

        if (ia == 4 .and. sa == 6) then
            print *, "Test for max value and index PASSED."
            result = 0
        else
            print *, "Test for max value and index FAILED."
            result = 1
        endif
    end subroutine testMaxValueAndIndex

    subroutine testMinValueAndIndex(a, result)
        integer, intent(in) :: a(10)
        integer, intent(out) :: result
        integer :: i, sa, ia

        sa = a(1)
        ia = 1
        do i = 2, 10
            if (sa > a(i)) then
                ia = i
                sa = a(i)
            endif
        enddo

        if (ia == 2 .and. sa == 1) then
            print *, "Test for min value and index PASSED."
            result = 0
        else
            print *, "Test for min value and index FAILED."
            result = 1
        endif
    end subroutine testMinValueAndIndex

end program main