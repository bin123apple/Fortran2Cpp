module bind_c_vars
  use, intrinsic :: iso_c_binding
  implicit none

  integer(c_int), bind(c) :: myF90Int
  real(c_float), bind(c, name="myF90Real") :: f90_real
  integer(c_int) :: c2
  integer(c_int) :: c3
  integer(c_int) :: c4
  bind(c, name="myVariable") :: c2
  bind(c) c3, c4 

  integer(c_int), bind(c, name="myF90Array3D") :: A(18, 3:7, 10)
  integer(c_int), bind(c, name="myF90Array2D") :: B(3, 2)

contains
  
  subroutine changeF90Globals() bind(c, name='changeF90Globals')
    implicit none
    myF90Int = myF90Int + 1
    f90_real = f90_real * 3.0
    c2 = c2 * 2
    c3 = c3 + 3
    c4 = c4 / 2
    A(5, 6, 3) = A(5, 6, 3) + 1
    B(3, 2) = B(3, 2) + 1
  end subroutine changeF90Globals

end module bind_c_vars

program test_bind_c_vars
  use bind_c_vars
  implicit none

  ! Initialize variables
  myF90Int = 0
  f90_real = 1.0
  c2 = 1
  c3 = 1
  c4 = 4
  A = 0
  B = 0

  ! Call the subroutine to modify the globals
  call changeF90Globals()

  ! Assertions (simple checks, for demonstration)
  if (myF90Int /= 1) stop 'Test failed for myF90Int'
  if (f90_real /= 3.0) stop 'Test failed for f90_real'
  if (c2 /= 2) stop 'Test failed for c2'
  if (c3 /= 4) stop 'Test failed for c3'
  if (c4 /= 2) stop 'Test failed for c4'
  if (A(5, 6, 3) /= 1) stop 'Test failed for A(5, 6, 3)'
  if (B(3, 2) /= 1) stop 'Test failed for B(3, 2)'

  print *, 'All tests passed!'
end program test_bind_c_vars