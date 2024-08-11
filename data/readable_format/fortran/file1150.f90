program testFunctionF
    implicit none

    ! Test variables
    character(len=5) :: testInput
    character(len=5) :: expectedOutput
    character(len=5) :: actualOutput

    ! Initialize test data
    testInput = "Hello"
    expectedOutput = "Hello"

    ! Call the function
    actualOutput = f(testInput)

    ! Check the result and print an appropriate message
    if (actualOutput == expectedOutput) then
        print *, "Test passed: ", actualOutput
    else
        print *, "Test failed: Expected ", expectedOutput, " but got ", actualOutput
    endif

contains

    ! Function f that simply returns its input string
    function f(x) result(res)
        character(len=*), intent(in) :: x
        character(len=len(x)) :: res
        res = x
    end function f

end program testFunctionF