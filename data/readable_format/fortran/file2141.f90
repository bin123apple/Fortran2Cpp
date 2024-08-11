program square_test
implicit none

integer :: test_number, squared_number

! Set a test number
test_number = 4

! Calculate the square of the test number
squared_number = square(test_number)

! Print the result
print *, 'The square of', test_number, 'is', squared_number

contains

function square(x) result(squareResult)
    integer, intent(in) :: x
    integer :: squareResult

    squareResult = x * x
end function square

end program square_test