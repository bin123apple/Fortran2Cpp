subroutine init_array(nr, nq, np, a, cFour)
implicit none

DATA_TYPE, dimension(np, nq, nr) :: a
DATA_TYPE, dimension(np, np) :: cFour
integer :: nr, nq, np
integer :: i, j, k

do i = 1, nr
do j = 1, nq
do k = 1, np
a(k, j, i) = ((DBLE(i - 1) * DBLE(j - 1)) + DBLE(k - 1)) / &
DBLE(np)
end do
end do
end do
do i = 1, np
do j = 1, np
cFour(j, i) = (DBLE(i - 1) * DBLE(j - 1)) / np
end do
end do
end subroutine
