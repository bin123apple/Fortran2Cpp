program test_vector_p2_exp_1d
  implicit none

  double precision :: xmin = 0.0, xmax = 1.0, alpha = 2.0
  complex*16 :: vecP2Exp(3)
  integer :: i

  call vector_p2_exp_1d(xmin, xmax, alpha, vecP2Exp)

  do i = 1, 3
      print *, 'vecP2Exp(', i, ') = ', vecP2Exp(i)
  end do

contains

  subroutine vector_p2_exp_1d(xmin, xmax, alpha, vecP2Exp)
    implicit none

    double precision, intent(in) :: xmin, xmax, alpha
    complex*16, intent(out) :: vecP2Exp(3)

    double precision :: fact1, alpha_h
    integer*8 :: dim1, i
    complex*16 :: ii, z_1, z_2, z_3

    ii = dcmplx(0.0d0, 1.0d0)

    alpha_h = alpha * (xmax - xmin)
    z_1 = exp(ii*alpha*xmin)
    z_2 = exp(ii*alpha*xmax)
    if(abs(alpha_h) > 1.0d-3) then
      vecP2Exp(1) = ii*(-4 + alpha_h**2 - 3*alpha_h*ii)*z_1 + (alpha_h + 4*ii)*z_2
      vecP2Exp(2) = (alpha_h - 4*ii)*z_1 - ii*(-4 + alpha_h**2 + 3*alpha_h*ii)*z_2
      vecP2Exp(3) = -4*( 2*ii*(-z_1 + z_2) + alpha_h*(z_1 + z_2) )
      fact1 = alpha**3*(xmax - xmin)**2
      dim1 = 3
      do i=1,dim1
        vecP2Exp(i) = vecP2Exp(i) / fact1
      enddo
    else
      z_3 = exp(ii*alpha*(xmax+xmin)/2.0d0)
      vecP2Exp(1) = (20 + alpha_h**2)*z_1
      vecP2Exp(2) = (20 + alpha_h**2)*z_2
      vecP2Exp(3) = -2*(-40 + alpha_h**2)*z_3
      fact1 = 120/(xmax - xmin)
      dim1 = 3
      do i=1,dim1
        vecP2Exp(i) = vecP2Exp(i) / fact1
      enddo
    endif
  end subroutine vector_p2_exp_1d

end program test_vector_p2_exp_1d