module progvars
  implicit none
  integer, parameter :: dp = kind(1.0d0)
end module progvars

module numerics
  use progvars
  implicit none

  contains

    subroutine linspace(x_min, x_max, x_arr, dx)
      implicit none
      real(dp), intent(in) :: x_min, x_max
      real(dp), intent(out) :: x_arr(:)
      real(dp), intent(out) :: dx
      integer :: i_x, n_x

      n_x = size(x_arr)
      dx = (x_max - x_min) / real(n_x - 1, dp)

      do i_x = 1, n_x
         x_arr(i_x) = x_min + (i_x - 1) * dx
      end do
    end subroutine linspace

end module numerics

program test_linspace
  use progvars
  use numerics
  implicit none

  real(dp) :: x_min, x_max, dx
  real(dp), allocatable :: x_arr(:)
  integer :: n_x, i

  x_min = 0.0_dp
  x_max = 10.0_dp
  n_x = 10
  allocate(x_arr(n_x))

  call linspace(x_min, x_max, x_arr, dx)

  print *, 'dx:', dx
  print *, 'x_arr:'
  do i = 1, n_x
     print "(F6.2)", x_arr(i)
  end do

  deallocate(x_arr)
end program test_linspace