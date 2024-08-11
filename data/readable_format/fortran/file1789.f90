program fortran_program
    implicit none
    character(64) :: line
    call performTests()
contains
    subroutine performTests()
        integer, parameter :: j = 4
        integer, parameter :: k = 8
        character(64) :: line

        write(line, '(F10.3, F10.3)') 0.0625_j, 0.1875_j
        call checkLine(line, "     0.062     0.188", 1)

        ! Additional tests would follow the same pattern...
    end subroutine performTests

    subroutine checkLine(line, expectedLine, testNumber)
        character(*), intent(in) :: line, expectedLine
        integer, intent(in) :: testNumber
        if (line /= expectedLine) then
            print *, "Test", testNumber, "FAILED."
        else
            print *, "Test", testNumber, "passed."
        end if
    end subroutine checkLine
end program fortran_program