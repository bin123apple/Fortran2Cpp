! Define a module to contain the square function
module math_operations
    implicit none
contains
    ! Calculates the square of a number
    function square(x)
        integer, intent(in) :: x
        integer :: square
        
        square = x * x
    end function square
end module math_operations

! Main program to test the square function
program test_square
    use math_operations
    implicit none
    
    integer :: input_number
    integer :: result
    
    ! Asking for a number to square
    print *, "Enter a number to square: "
    read *, input_number
    
    result = square(input_number)
    
    print *, "The square of ", input_number, " is ", result
end program test_square