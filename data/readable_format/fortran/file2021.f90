module constants
  implicit none
  double precision, parameter :: ZERO = 0.0d0
  double precision, parameter :: PI = 3.14159265358979323846d0
  double precision, parameter :: TWO_PI = 2.0d0 * PI
  double precision, parameter :: TINYVAL = 1.0d-10
end module constants

program test_reduce
  use constants
  implicit none

  double precision :: theta, phi

  ! Test 1
  theta = -0.1d0
  phi = TWO_PI + 0.1d0
  call reduce(theta, phi)
  print *, "Test 1 (Theta, Phi): ", theta, phi

  ! Test 2
  theta = 3*PI/2
  phi = -0.1d0
  call reduce(theta, phi)
  print *, "Test 2 (Theta, Phi): ", theta, phi

contains

  subroutine reduce(theta, phi)
    use constants
    implicit none
    double precision, intent(inout) :: theta, phi
    integer :: i
    double precision :: th, ph

    ! Subroutine body remains same as provided earlier
    ! Ensure to include the original logic of the subroutine here

  end subroutine reduce

end program test_reduce