module matvec_module
  implicit none
contains

subroutine matvec(n, x, y, nelt, ia, ja, a, isym)
  integer, intent(in) :: n, nelt, ia(*), ja(*), isym
  real(8), intent(in) :: x(*), a(*)
  real(8), intent(out) :: y(*)
  integer :: i, j, l, nd, na

  nd = nelt - n
  if (isym == 0) then
     na = nd / 2
     do i = 1, n
        y(i) = a(nd + i) * x(i)
     end do
     do j = 1, n
        do l = ja(j), ja(j + 1) - 1
           i = ia(l)
           y(i) = y(i) + a(l) * x(j)
        end do
     end do
     do j = 1, n
        do l = ja(j), ja(j + 1) - 1
           i = ia(l)
           y(j) = y(j) + a(l + na) * x(i)
        end do
     end do
  else
     ! Handle the symmetric case if required
  endif
end subroutine matvec

end module matvec_module

program test_matvec
  use matvec_module
  implicit none
  integer, parameter :: n = 5, nelt = 10
  integer :: ia(nelt), ja(n+1), isym
  real(8) :: x(n), y(n), a(nelt)
  integer :: i

  ! Initialize variables
  isym = 0
  ia = (/1, 2, 3, 4, 5, 1, 2, 3, 4, 5/)
  ja = (/1, 3, 5, 7, 9, 11/)
  a = (/1.0d0, 2.0d0, 3.0d0, 4.0d0, 5.0d0, 0.5d0, 1.5d0, 2.5d0, 3.5d0, 4.5d0/)
  x = (/1.0d0, 2.0d0, 3.0d0, 4.0d0, 5.0d0/)
  y = 0.0d0

  ! Call the subroutine
  call matvec(n, x, y, nelt, ia, ja, a, isym)

  ! Print the results
  print *, 'y = ', y

end program test_matvec