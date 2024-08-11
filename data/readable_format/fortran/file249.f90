program SquareNumber
    implicit none
    integer :: number, squaredNumber

    ! Asking for user input
    print *, 'Enter a number to square:'
    read *, number

    ! Calculating the square
    squaredNumber = square(number)

    ! Displaying the result
    print *, 'The square of', number, 'is', squaredNumber

contains

    ! Function to square a number
    function square(x) result(squareResult)
        implicit none
        integer, intent(in) :: x
        integer :: squareResult

        squareResult = x * x
    end function square

end program SquareNumber