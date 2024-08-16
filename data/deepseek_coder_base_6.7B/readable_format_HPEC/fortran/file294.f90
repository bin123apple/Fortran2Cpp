subroutine init_array(n, a, b)
implicit none

DATA_TYPE, dimension(n) :: a
DATA_TYPE, dimension(n) :: b
integer :: n
integer :: i

do i = 1, n
a(i) = (DBLE(i-1) + 2.0D0) / n
b(i) = (DBLE(i-1) + 3.0D0) / n
end do
end subroutine
