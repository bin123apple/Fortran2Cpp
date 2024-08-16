subroutine init_array(m, n, float_n, dat)
implicit none

DATA_TYPE, dimension(n, m) :: dat
DATA_TYPE :: float_n
integer :: m, n
integer :: i, j

float_n = 1.2D0
do i = 1, m
do j = 1, n
dat(j, i) = (DBLE((i - 1) * (j - 1))) / DBLE(m)
end do
end do
end subroutine
