program transf_test
    implicit none

    type g1
        integer :: a(3)
        real(8) :: r(3)
    end type g1

    type(g1) :: ex, goal
    character :: mold(0)

    ex%a = 3
    ex%r = 1.2

    goal = transfer(transfer(ex,mold),ex)

    ! Simple test to check if goal has the expected values
    if (goal%a(1) == 3 .and. abs(goal%r(1) - 1.2) < 0.0001) then
        print *, "Test passed."
    else
        print *, "Test failed."
    end if

end program transf_test