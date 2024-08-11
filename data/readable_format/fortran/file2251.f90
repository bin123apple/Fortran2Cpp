program main
    implicit none
    call greet
    call performCalculation
end program main

subroutine greet
    print *, "Hello, World!"
end subroutine greet

subroutine performCalculation
    implicit none
    integer :: a, b, sum
    a = 5
    b = 10
    call addNumbers(a, b, sum)
    print *, "The sum is: ", sum
end subroutine performCalculation

subroutine addNumbers(a, b, sum)
    implicit none
    integer, intent(in) :: a, b
    integer, intent(out) :: sum
    sum = a + b
end subroutine addNumbers