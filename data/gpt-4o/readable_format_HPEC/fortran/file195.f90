subroutine kernel_doitgen(nr, nq, np , &
a, cFour, sumA)
implicit none

DATA_TYPE, dimension(np, nq, nr) :: a
DATA_TYPE, dimension(np, nq, nr) :: sumA
DATA_TYPE, dimension(np, np) :: cFour
integer :: nr, nq, np
integer :: r, s, p, q

!$pragma scop
do r = 1, _PB_NR
do q = 1, _PB_NQ
do p = 1, _PB_NP
sumA(p, q, r) = 0.0D0
do s = 1, _PB_NP
sumA(p, q, r) = sumA(p, q, r) + (a(s, q, r) * &
cFour(p, s))
end do
end do
do p = 1, _PB_NP
a(p, q, r) = sumA(p, q, r)
end do
end do
end do
!$pragma endscop
end subroutine
