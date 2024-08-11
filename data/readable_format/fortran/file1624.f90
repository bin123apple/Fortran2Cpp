program test_user
    implicit none
    real :: a, b, c
    common /vars/ a, b, c
    real :: eps = 0.00001

    ! Test 1: Expected OK
    a = 3.0
    b = 4.0
    c = 5.0
    call check_values()

    ! Test 2: Expected NG (Change to values that will fail the test)
    a = 3.1
    b = 4.0
    c = 5.0
    call check_values()

contains

    subroutine check_values()
        if (abs(a-3.)<eps .and. abs(b-4.)<eps .and. abs(c-5.)<eps) then
            print *, "Test OK"
        else
            print *, "Test NG"
            ! Note: For unit testing, we generally allow the program to continue 
            ! running other tests instead of exiting.
        endif
    end subroutine check_values

end program test_user