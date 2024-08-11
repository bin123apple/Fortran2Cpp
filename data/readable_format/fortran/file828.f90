program test_set_value
    implicit none
    integer :: testVar

    ! Initialize testVar to a value other than 2 to test the subroutine
    testVar = 0
    print *, "Before: testVar =", testVar

    ! Call the subroutine to set testVar to 2
    call set_value_to_2(testVar)

    print *, "After: testVar =", testVar

    ! Test if the subroutine works correctly
    if (testVar == 2) then
        print *, "Test passed: testVar is 2."
    else
        print *, "Test failed: testVar is not 2."
    endif
contains

    subroutine set_value_to_2(a)
        implicit none
        integer :: a

        a = 2
    end subroutine set_value_to_2

end program test_set_value