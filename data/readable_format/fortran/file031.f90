subroutine squareNumber(inputNumber, result)
    ! Declare variables
    integer, intent(in) :: inputNumber
    integer, intent(out) :: result

    ! Calculate the square
    result = inputNumber * inputNumber
end subroutine squareNumber