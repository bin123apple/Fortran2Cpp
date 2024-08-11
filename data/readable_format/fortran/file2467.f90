! File: test_fortran.f90
program test_fortran
    implicit none

    character(1) :: c
    common /x/ c

    ! Set the value of 'c'
    c = 'A'

    ! Call the subroutine to check the value
    call check_value()

contains

    subroutine check_value()
        character(1) :: c
        common /x/ c

        if (c .eq. 'A') then
            print *, 'Test Passed: c = ', c
        else
            print *, 'Test Failed: c = ', c
        end if
    end subroutine check_value

end program test_fortran