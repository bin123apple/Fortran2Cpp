module calc_module
  implicit none
contains
  subroutine calcpel(ne, vel, b, nef)
    implicit none
    integer :: ne, nef
    real(8) :: vel(ne, 0:5), b(ne)
    integer :: i
    do i = 1, ne
       vel(i, 4) = vel(i, 4) + b(i)
    enddo
  end subroutine calcpel
end module calc_module

program testCalcpel
  use calc_module
  implicit none
  integer, parameter :: ne = 3, nef = 6
  real(8) :: vel(ne, 0:5), b(ne)
  integer :: i

  ! Initialize arrays for testing
  do i = 1, ne
     vel(i, :) = 0.0
     b(i) = i * 1.0
  enddo

  ! Call the subroutine
  call calcpel(ne, vel, b, nef)

  ! Output for verification
  do i = 1, ne
     print *, 'vel(', i, ', 4) = ', vel(i, 4)
  enddo
end program testCalcpel