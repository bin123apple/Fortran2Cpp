! laplace_corrected.f90
module laplace_mod
  implicit none
  integer, parameter :: N1=64, N2=64
  real(8), parameter :: PI = 3.141592653589793238463
contains
  subroutine laplace(value)
    integer :: niter=100
    real(8) :: u(N1,N2), uu(N1,N2)
    real(8), intent(out) :: value
    integer :: i, j, k

    value = 0.0
    ! Initialize arrays
    u = 0.0
    uu = 0.0

    ! Boundary conditions
    do j=2,N2-1
       do i=2,N1-1
          u(i,j)=sin(real(i-1)/N1*PI)+cos(real(j-1)/N2*PI)
       end do
    end do

    ! Main iteration
    do k=1,niter
       uu = u
       do j=2,N2-1
          do i=2,N1-1
             u(i,j)=(uu(i-1,j) + uu(i+1,j) + uu(i,j-1) + uu(i,j+1))/4.0
          end do
       end do
    end do

    ! Compute the verification value
    do j=2,N2-1
       do i=2,N1-1
          value = value + abs(uu(i,j) - u(i,j))
       end do
    end do
  end subroutine laplace
end module

program test_laplace
  use laplace_mod
  real(8) :: value

  call laplace(value)
  print *, 'Verification =', value
end program