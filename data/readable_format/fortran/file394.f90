! hello.f90
program hello
    implicit none
    call greet
    call performCalculation
end program hello

subroutine greet
    print *, "Hello, World!"
end subroutine greet

subroutine performCalculation
    integer :: result
    result = 3 + 4
    print *, "The sum of 3 and 4 is ", result, "."
end subroutine performCalculation