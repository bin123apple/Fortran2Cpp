program test_fpchec
  implicit none
  integer :: m, n, k, ier
  double precision, allocatable :: x(:), t(:)
  
  ! Test case setup
  m = 5
  n = 7
  k = 2
  allocate(x(m), t(n))
  x = [1.0d0, 2.0d0, 3.0d0, 4.0d0, 5.0d0]
  t = [0.0d0, 0.5d0, 1.0d0, 2.0d0, 3.0d0, 4.0d0, 5.0d0]
  
  ! Call the subroutine
  call fpchec(x, m, t, n, k, ier)
  
  ! Output the result
  print *, "Test 1: ier =", ier
  
  ! Clean up
  deallocate(x, t)
  
contains
  subroutine fpchec(x, m, t, n, k, ier)
    implicit none
    integer, intent(in) :: m, n, k
    double precision, intent(in) :: x(m), t(n)
    integer, intent(out) :: ier
    integer :: i, j, k1, k2, l, nk1, nk2, nk3
    double precision :: tj, tl

    k1 = k + 1
    k2 = k1 + 1
    nk1 = n - k1
    nk2 = nk1 + 1
    ier = 10
    if (nk1 < k1 .or. nk1 > m) return
    j = n
    do 20 i = 1, k
      if (t(i) > t(i+1) .or. t(j) < t(j-1)) return
      j = j - 1
20  continue
    do 30 i = k2, nk2
      if (t(i) <= t(i-1)) return
30  continue
    if (x(1) < t(k1) .or. x(m) > t(nk2)) return
    if (x(1) >= t(k2) .or. x(m) <= t(nk1)) return
    i = 1
    l = k2
    nk3 = nk1 - 1
    if (nk3 < 2) then
      ier = 0
      return
    end if
    do 60 j = 2, nk3
      tj = t(j)
      tl = t(l)
40    i = i + 1
      if (i > m) return
      if (x(i) <= tj) goto 40
      if (x(i) >= tl) return
      l = l + 1
60  continue
    ier = 0
  end subroutine fpchec
end program test_fpchec