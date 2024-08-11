program test_main
use, intrinsic :: iso_fortran_env, only : error_unit, sp=>real32, dp=>real64
implicit none

real(sp) :: a32
real(dp) :: a64
integer :: a_int

real(sp), parameter :: pi32 = 4*atan(1._sp)
real(dp), parameter :: pi64 = 4*atan(1._dp)

call test_timestwo

contains

elemental subroutine timestwo(a)
class(*), intent(inout) :: a
select type (a)
  type is (real(sp))
    a = 2*a
  type is (real(dp))
    a = 2*a
  type is (integer)
    a = 2*a
end select
end subroutine timestwo

subroutine test_timestwo
    a32 = 1.0_sp
    call timestwo(a32)
    if (a32 /= 2.0_sp) then
        print *, "Test failed for real32: expected 2.0, got ", a32
        stop 1
    end if

    a64 = 1.0_dp
    call timestwo(a64)
    if (a64 /= 2.0_dp) then
        print *, "Test failed for real64: expected 2.0, got ", a64
        stop 1
    end if

    a_int = 1
    call timestwo(a_int)
    if (a_int /= 2) then
        print *, "Test failed for integer: expected 2, got ", a_int
        stop 1
    end if

    print *, "All tests passed."
end subroutine test_timestwo

end program test_main