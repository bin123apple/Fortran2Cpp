subroutine kernel_adi(tsteps, n, x, a, b)
implicit none

DATA_TYPE, dimension(n, n) :: a
DATA_TYPE, dimension(n, n) :: x
DATA_TYPE, dimension(n, n) :: b
integer :: n, tsteps
integer :: i1, i2, t

!$pragma scop
do t = 1, _PB_TSTEPS
do i1 = 1, _PB_N
do i2 = 2, _PB_N
x(i2, i1) = x(i2, i1) - ((x(i2 - 1, i1) * a(i2, i1)) / &
b(i2 - 1, i1))
b(i2, i1) = b(i2, i1) - ((a(i2, i1) * a(i2, i1)) / &
b(i2 - 1, i1))
end do
end do

do i1 = 1, _PB_N
x(_PB_N, i1) = x(_PB_N, i1) / b(_PB_N, i1)
end do

do i1 = 1, _PB_N
do i2 = 1, _PB_N - 2
x(_PB_N - i2, i1) = (x(_PB_N - i2, i1) - &
(x(_PB_N - i2 - 1, i1) * &
a(_PB_N - i2 - 1, i1))) / &
b(_PB_N - i2 - 1, i1)
end do
end do

do i1 = 2, _PB_N
do i2 = 1, _PB_N
x(i2, i1) = x(i2, i1) - x(i2, i1 - 1) * a(i2, i1) / &
b(i2, i1 - 1)
b(i2, i1) = b(i2, i1) - a(i2, i1) * a(i2, i1) / &
b(i2, i1 - 1)

end do
end do

do i2 = 1, _PB_N
x(i2, _PB_N) = x(i2, _PB_N) / b(i2, _PB_N)
end do

do i1 = 1, _PB_N - 2
do i2 = 1, _PB_N
x(i2, _PB_N - i1) = (x(i2, _PB_N - i1) - &
x(i2, _PB_N - i1 - 1) * &
a(i2, _PB_N - i1 - 1)) / &
b(i2, _PB_N - i1)
end do
end do
end do
!$pragma endscop
end subroutine
