subroutine reorderrhs(a, b, vold, neighblock, nneighblock)
  implicit none
  integer, intent(in) :: neighblock(3,*), nneighblock
  real(8), intent(in) :: a(*), vold(*)
  real(8), intent(inout) :: b(*)
  integer :: j, indexf, iel, i

  do j = 1, nneighblock
     indexf = neighblock(1, j)
     iel = neighblock(2, j)
     i = neighblock(3, j)
     b(i) = b(i) - a(indexf) * vold(iel)
  end do
end subroutine reorderrhs

program test
  implicit none
  integer, parameter :: n = 5
  integer, parameter :: nneighblock = 3
  integer :: neighblock(3,nneighblock) = reshape((/1, 4, 2, 3, 1, 3, 5, 3, 5/), shape(neighblock), order=[2,1])
  real(8) :: a(n) = (/1.0d0, 2.0d0, 3.0d0, 4.0d0, 5.0d0/)
  real(8) :: b(n) = (/0.0d0, 0.0d0, 0.0d0, 0.0d0, 0.0d0/)
  real(8) :: vold(n) = (/10.0d0, 20.0d0, 30.0d0, 40.0d0, 50.0d0/)
  integer :: i

  call reorderrhs(a, b, vold, neighblock, nneighblock)

  print *, 'Resulting b array:'
  do i = 1, n
     print *, 'b(', i, ') = ', b(i)
  end do
end program test