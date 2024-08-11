program test_assert_equal

implicit none

! Test cases
call assert_equal(1 / 5., 0.2)
call assert_equal(1. / 5, 0.2)
call assert_equal(4*atan(1.), 3.14159265359)
call assert_equal(1 + 4., 5.)
call assert_equal(0.3, 0.1 + 0.2, 1e-6) ! A test case that might fail due to floating-point arithmetic

contains

subroutine assert_equal(val, ref, atol)
real, intent(in) :: val, ref
real, intent(in), optional :: atol

real :: a

a = 0.0001
if(present(atol)) a = atol

if (abs(val - ref) > a) then
    print *, "Assertion failed: ", val, " != ", ref
    error stop 1
end if

end subroutine assert_equal

end program