module foodie_error_codes
  use, intrinsic :: iso_fortran_env, only : int32
  implicit none
  private
  public :: ERROR_UNSUPPORTED_SCHEME
  integer(int32), parameter :: ERROR_UNSUPPORTED_SCHEME = 1 
end module foodie_error_codes

program test_foodie_error_codes
  use foodie_error_codes
  implicit none

  ! Test the ERROR_UNSUPPORTED_SCHEME constant
  write(*,*) 'Testing ERROR_UNSUPPORTED_SCHEME...'
  if (ERROR_UNSUPPORTED_SCHEME == 1) then
    write(*,*) 'Test passed: ERROR_UNSUPPORTED_SCHEME = 1'
  else
    write(*,*) 'Test failed: ERROR_UNSUPPORTED_SCHEME /= 1'
  endif
end program test_foodie_error_codes