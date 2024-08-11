module averms_module
  implicit none
contains
  subroutine averms(x, npts, ave, rms, xmax)
    real, intent(in) :: x(:)
    real, intent(out) :: ave, rms, xmax
    real :: s, sq
    integer :: i, npts

    s = 0.0
    xmax = 0.0
    do i = 1, npts
       s = s + x(i)
       xmax = max(xmax, abs(x(i)))
    end do
    ave = s / npts

    sq = 0.0
    do i = 1, npts
       sq = sq + (x(i) - ave)**2
    end do
    rms = sqrt(sq / (npts - 1))
  end subroutine averms
end module averms_module

program test_averms
  use averms_module
  implicit none
  real, dimension(5) :: x = [1.0, 2.0, 3.0, 4.0, 5.0]
  real :: ave, rms, xmax

  call averms(x, size(x), ave, rms, xmax)

  print *, 'Average: ', ave
  print *, 'RMS: ', rms
  print *, 'Maximum: ', xmax

  ! Expected output:
  ! Average: 3.0
  ! RMS: 1.58114 (approximately, depending on precision)
  ! Maximum: 5.0
end program test_averms