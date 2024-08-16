subroutine init_array(length, c, w)
implicit none

DATA_TYPE, dimension(length, length) :: w, c
integer :: i, j
integer length

do i = 1, length
do j = 1, length
c(j, i) = mod((i-1)*(j-1), 2)
w(j, i) = (DBLE((i - 1) - (j - 1))) / DBLE(length)
end do
end do
end subroutine
