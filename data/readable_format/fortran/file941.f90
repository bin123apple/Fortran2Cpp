program test_per_credat
  implicit none
  
  ! Declare variables for the test
  integer, parameter :: nval = 5
  real, dimension(nval) :: x, y
  double precision, dimension(20) :: f
  double precision, dimension(21) :: c
  double precision, dimension(20) :: p
  integer :: nf = 2
  logical :: epfl = .true.
  double precision, dimension(2) :: ep = (/0.0, 10.0/)
  double precision :: epoch = 5.0, freq = 1.0
  
  ! Initialize arrays
  f(1:2) = (/1.0, 2.0/)
  c(1:3) = (/0.0, 1.0, 0.5/)
  p(1:2) = (/0.0, 3.14/)
  
  ! Call the subroutine
  call per_credat(x, y, nval, f, c, p, nf, epfl, ep, epoch, freq)
  
  ! Print results for verification
  print *, 'X:', x
  print *, 'Y:', y

contains

  subroutine per_credat(x, y, nval, f, c, p, nf, epfl, ep, epoch, freq)
    ! Declare subroutine arguments and local variables
    integer, intent(in) :: nval, nf
    real, dimension(nval), intent(out) :: x, y
    double precision, dimension(:), intent(in) :: f, c, p, ep
    double precision, intent(in) :: epoch, freq
    logical, intent(in) :: epfl
    double precision :: delt, t
    integer :: i, j

    delt = (ep(2)-ep(1))/dble(nval-1)

    do i=1,nval
       if (epfl) then
          x(i) = ep(1) + dble(i-1)*delt
          t = (dble(x(i))-epoch)*6.283185d0
       else
          x(i) = real(i-1)/real(nval-1)
          t = (dble(x(i))/freq + ep(1) - epoch)*6.283185d0
       end if

       y(i) = c(1)

       do j = 1,nf
          y(i) = y(i) + c(j+1)*sin(t*f(j)+p(j))
       end do
    end do
  end subroutine per_credat

end program test_per_credat