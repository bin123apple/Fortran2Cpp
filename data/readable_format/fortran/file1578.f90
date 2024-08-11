module PARAMETERS
  implicit none
  real, parameter :: d2r = asin(1e0)/9e1
  real :: mu=40e09, moment = 5.593e22
  real(kind=4) :: al1, al2, aw1, aw2

  real(kind=4) ::  alpha = 2e0/3e0
  real(kind=4) ::  depth = 10e0
  real(kind=4) ::  dip = 9e0
  real(kind=4) ::  length=250e0
  real(kind=4) ::  rake=78e0*d2r
  real(kind=4) ::  strike=(180e0-193e0)*d2r

contains

  subroutine start_parameters
    al2 = length/2e0
    al1 = -al2
    aw1 = -150e0
    aw2 = 0e0
  end subroutine

end module

program test_parameters
  use PARAMETERS
  implicit none

  ! Initialize the module parameters
  call start_parameters

  ! Test the constants
  if (d2r /= asin(1e0)/9e1) then
      print *, "Test failed for d2r"
  end if
  if (mu /= 40e09) then
      print *, "Test failed for mu"
  end if
  if (moment /= 5.593e22) then
      print *, "Test failed for moment"
  end if

  ! Test the results of start_parameters
  if (al1 /= -length/2.0) then
      print *, "Test failed for al1"
  end if
  if (al2 /= length/2.0) then
      print *, "Test failed for al2"
  end if
  if (aw1 /= -150.0) then
      print *, "Test failed for aw1"
  end if
  if (aw2 /= 0.0) then
      print *, "Test failed for aw2"
  end if

  print *, "Fortran tests completed."
end program