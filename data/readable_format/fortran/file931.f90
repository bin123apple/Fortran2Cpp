module types
  implicit none
  public :: dp
  integer, parameter :: dp = kind(0.d0)
end module types

program test_types
  use types
  implicit none

  ! Variable to test the kind
  real(dp) :: testVar

  ! Print information about the kind
  print *, "Kind of dp: ", kind(testVar)

  ! Example condition to check if dp is double precision
  if (kind(testVar) == kind(0.d0)) then
    print *, "Test passed: dp is double precision."
  else
    print *, "Test failed: dp is not double precision."
  end if
end program test_types