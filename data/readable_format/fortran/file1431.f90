program test
  implicit none
  real :: theta
  real, parameter :: pi = 3.14159265358979323846
  integer :: i
  real, dimension(4) :: test_angles = [0.0, pi/4, pi/2, 3*pi/4]

  do i = 1, size(test_angles)
    theta = test_angles(i)

    associate (n => [cos(theta), sin(theta)])
      if (abs (norm2(n) - 1.0) .gt. 1.0e-4) then
        print *, "Test failed for theta =", theta
        STOP 1
      else
        print *, "Test passed for theta =", theta
      end if
    end associate
  end do

end program test