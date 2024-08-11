program rescalenonlinear
  implicit none
  double precision, parameter :: POWERVAL = 0.25d0
  double precision :: a
  integer :: i

  do i = 1, 9
     a = i / 10.0d0
     call print_rescale(a)
  end do
end program rescalenonlinear

subroutine print_rescale(a)
  double precision, intent(in) :: a
  double precision, parameter :: POWERVAL = 0.25d0
  write(*,*) a, ' gives ', a**POWERVAL
end subroutine print_rescale