program poly_test

use, intrinsic :: iso_fortran_env
implicit none

integer, parameter :: wp = real64

real(wp), parameter :: pi = 4._wp * atan(1._wp)
real(wp) :: expected, result

expected = 2 * pi
result = timestwo(pi)

if (abs(result - expected) < 1.0E-8_wp) then
    print *, "Test passed: Result is", result
else
    print *, "Test failed: Result", result, "Expected", expected
end if

contains

elemental real(wp) function timestwo(a) result(a2)
    real(wp), intent(in) :: a
    a2 = 2 * a
end function timestwo

end program