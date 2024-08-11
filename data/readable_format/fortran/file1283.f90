program mainProgram
    implicit none
    ! Variable declarations
    integer :: a, b, sumResult

    ! Initialize variables
    a = 5
    b = 10

    ! Call the add subroutine
    call add(a, b, sumResult)
    print *, "The sum of ", a, " and ", b, " is ", sumResult

    ! Call other functions or subroutines as needed
end program mainProgram

! Subroutine to add two numbers
subroutine add(x, y, result)
    ! Declaration of variables
    integer, intent(in) :: x, y
    integer, intent(out) :: result

    ! Calculate sum
    result = x + y
end subroutine add

! You can define more subroutines or functions here