program test_phi1_2d_mat
  implicit none
  double precision :: x(2), phi(3), mat_grad(2,3)
  integer :: i, j

  ! Define a test case
  x(1) = 0.5
  x(2) = 0.25

  ! Call the subroutine
  call phi1_2d_mat(x, phi, mat_grad)

  ! Output the results
  do i = 1, 3
     print *, 'phi(', i, ') = ', phi(i)
  end do

  do i = 1, 2
     do j = 1, 3
        print *, 'mat_grad(', i, ',', j, ') = ', mat_grad(i,j)
     end do
  end do
end program test_phi1_2d_mat

subroutine phi1_2d_mat(x, phi, mat_grad)
  implicit none
  double precision, intent(in) :: x(2)
  double precision, intent(out) :: phi(3), mat_grad(2,3)
  double precision :: x0, y0
  integer*8 :: inode

  x0 = x(1)
  y0 = x(2)

  inode = 1
    phi(inode) = 1 - x0 - y0
    mat_grad(1,inode) = -1
    mat_grad(2,inode) = -1

  inode = 2
    phi(inode) = x0
    mat_grad(1,inode) = 1
    mat_grad(2,inode) = 0

  inode = 3
    phi(inode) = y0
    mat_grad(1,inode) = 0
    mat_grad(2,inode) = 1
end subroutine phi1_2d_mat