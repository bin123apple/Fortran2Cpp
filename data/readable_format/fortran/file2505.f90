program test_myadd
    implicit none

    ! Test variables
    integer :: expected_result
    integer :: test_result

    ! Test myadd function
    expected_result = 5
    test_result = myadd(2, 3)

    if (test_result == expected_result) then
        print *, "Test passed: myadd(2, 3) = ", test_result
    else
        print *, "Test failed: Expected ", expected_result, " but got ", test_result
    endif

contains

    function myadd(d, e) result(f)
        implicit none
        integer, intent(in) :: d, e
        integer :: f

        f = d + e
    end function myadd

end program test_myadd