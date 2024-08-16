subroutine init_array(n, p, a)
implicit none

DATA_TYPE, dimension(n, n) :: a
DATA_TYPE, dimension(n) :: p
integer :: n
integer :: i, j
do i = 1, n
p(i) = 1.0D0  / n
do j = 1, n
a(j, i) =  1.0D0 / n
end do
end do
end subroutine
