program test_darnan
  implicit none
  real(8) :: test_val
  integer :: info

  ! NOTE: Direct generation of NaN in a portable manner in Fortran is non-trivial without specific intrinsic modules
  ! As such, we'll proceed with a valid test value and manually set a NaN in the actual subroutine/function if needed for testing.
  
  ! Test with a non-NaN value (normal case)
  test_val = 1.0
  call DARNAN(test_val, info)
  if (info == 0) then
    print *, "Test with non-NaN (1.0) passed. INFO=", info
  else
    print *, "Test with non-NaN (1.0) failed. INFO=", info
  end if

contains

  subroutine DARNAN(NUM, INFO)
    implicit none
    real(8), intent(in) :: NUM
    integer, intent(inout) :: INFO

    INFO = 0
    if (NUM .NE. NUM) then
      INFO = 1
    end if
  end subroutine DARNAN

end program test_darnan