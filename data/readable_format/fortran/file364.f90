program test_great_rsd
    implicit none

    ! Test variables
    integer :: a, b, result

    ! Test cases
    a = 5; b = 3
    result = great_rsd(a, b)
    call assert_equals(8, result, "Test 1")

    a = -1; b = 1
    result = great_rsd(a, b)
    call assert_equals(0, result, "Test 2")

    a = -5; b = -10
    result = great_rsd(a, b)
    call assert_equals(-15, result, "Test 3")

contains

    function great_rsd(a, b)
        integer, intent(in) :: a, b
        integer :: great_rsd
        great_rsd = a + b
    end function great_rsd

    subroutine assert_equals(expected, actual, message)
        integer, intent(in) :: expected, actual
        character(len=*), intent(in) :: message
        if (expected /= actual) then
            print *, trim(message) // " failed. Expected: ", expected, " Got: ", actual
        else
            print *, trim(message) // " passed."
        endif
    end subroutine assert_equals

end program test_great_rsd