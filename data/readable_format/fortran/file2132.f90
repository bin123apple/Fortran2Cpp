! main.f90
program main_program
  use, intrinsic :: iso_fortran_env, only : sp=>real32, dp=>real64
  implicit none

  real(sp) :: a32
  real(dp) :: a64

  a32 = 1.0_sp
  a64 = 1.0_dp

  call timestwo(a32)
  call timestwo(a64)

  print *, 'a32 (after) = ', a32
  print *, 'a64 (after) = ', a64

contains

  elemental subroutine timestwo(a)
    class(*), intent(inout) :: a

    select type (a)
      type is (real(sp))
        a = 2*a
      type is (real(dp))
        a = 2*a
    end select
  end subroutine timestwo

end program main_program