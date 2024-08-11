module arg_nut

  implicit none

  integer, parameter        :: xi = selected_real_kind (15)
  real (kind=xi), parameter :: pi = 4._xi*atan(1._xi)

  real (kind=xi), parameter :: t2000 = 51544.5
  real (kind=xi), parameter :: Nbr_days_in_Century = 36525

  real(kind = xi), parameter :: phil     = 134.96340251_xi*pi/180._xi
  real(kind = xi), parameter :: phils    = 357.52910918_xi*pi/180._xi
  real(kind = xi), parameter :: phiF     = 93.27209062_xi*pi/180._xi
  real(kind = xi), parameter :: phiD     = 297.85019547_xi*pi/180._xi
  real(kind = xi), parameter :: phiomega = 125.04455501_xi*pi/180._xi

  real(kind = xi), parameter :: sigmal     = 1717915923.2178_xi/3600._xi*pi/180._xi
  real(kind = xi), parameter :: sigmals    = 129596581.0481_xi/3600._xi*pi/180._xi
  real(kind = xi), parameter :: sigmaF     = 1739527262.8478_xi/3600._xi*pi/180._xi
  real(kind = xi), parameter :: sigmaD     = 1602961601.2090_xi/3600._xi*pi/180._xi
  real(kind = xi), parameter :: sigmaomega = -6962890.5431_xi/3600._xi*pi/180._xi

contains

end module arg_nut

program test_arg_nut
  use arg_nut
  implicit none
  
  print *, "Testing arg_nut module constants"
  print *, "pi should be approximately 3.14159, actual:", pi
  print *, "t2000 should be 51544.5, actual:", t2000
  print *, "Nbr_days_in_Century should be 36525, actual:", Nbr_days_in_Century
  print *, "phil should be:", phil
  print *, "phils should be:", phils
  print *, "phiF should be:", phiF
  print *, "phiD should be:", phiD
  print *, "phiomega should be:", phiomega
  print *, "sigmal should be:", sigmal
  print *, "sigmals should be:", sigmals
  print *, "sigmaF should be:", sigmaF
  print *, "sigmaD should be:", sigmaD
  print *, "sigmaomega should be:", sigmaomega

  ! Perform simple checks
  if (abs(pi - 3.14159) > 1e-5) then
    print *, "Test for pi failed."
  else
    print *, "Test for pi passed."
  endif

  ! Add similar checks for other constants if needed...

end program test_arg_nut