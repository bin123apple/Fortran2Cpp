program t_test
    implicit none
    integer :: result

    ! Test when condition is true
    result = testEndxyz(.true.)
    print *, "Test when condition is true. Expected: 2, Got:", result

    ! Test when condition is false
    result = testEndxyz(.false.)
    print *, "Test when condition is false. Expected: 1, Got:", result

contains

    function testEndxyz(condition) result(endxyz)
        logical, intent(in) :: condition
        integer :: endxyz

        endxyz = 1
        if (condition) then
            endxyz = 2
        endif
    end function testEndxyz

end program t_test