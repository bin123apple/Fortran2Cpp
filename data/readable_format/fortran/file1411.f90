program main
    implicit none
    integer, dimension(2,3) :: a
    call initializeArray(a)
    call printArray(a)
    call testArrayInitialization(a)
contains

    subroutine initializeArray(a)
        integer, dimension(2,3), intent(out) :: a
        integer :: row, col, count
        count = 0
        do row = 1,2
            do col = 1,3
                count = count + 1
                a(row,col) = count
            end do
        end do
    end subroutine initializeArray

    subroutine printArray(a)
        integer, dimension(2,3), intent(in) :: a
        integer :: row, col
        do row = 1,2
            do col = 1,3
                print *, a(row,col)
            end do
        end do
    end subroutine printArray

    subroutine testArrayInitialization(a)
        integer, dimension(2,3), intent(in) :: a
        integer :: row, col, expectedValue
        logical :: testPassed
        testPassed = .TRUE.
        expectedValue = 1
        do row = 1,2
            do col = 1,3
                if (a(row,col) /= expectedValue) then
                    testPassed = .FALSE.
                    exit
                endif
                expectedValue = expectedValue + 1
            end do
            if (.NOT. testPassed) exit
        end do

        if (testPassed) then
            print *, "Fortran Test passed: Array initialized correctly."
        else
            print *, "Fortran Test failed: Array not initialized as expected."
        endif
    end subroutine testArrayInitialization

end program main