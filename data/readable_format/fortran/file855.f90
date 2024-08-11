program doubleNumberTest
    implicit none
    integer :: inputNumber
    integer :: result

    ! Example input
    inputNumber = 4
    call doubleNumber(inputNumber, result)
    print *, 'Double of', inputNumber, 'is', result

contains

    subroutine doubleNumber(inputNumber, outputNumber)
        integer, intent(in) :: inputNumber
        integer, intent(out) :: outputNumber
        outputNumber = 2 * inputNumber
    end subroutine doubleNumber

end program doubleNumberTest