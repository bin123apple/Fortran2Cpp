! File: nidentll.f90
subroutine nidentll(x, px, n, id)
      implicit none
      integer n, id, n2, m
      integer*8 x(n), px
      id = 0
      if (n .eq. 0) return
      n2 = n + 1
      do
         m = (n2 + id) / 2
         if (px .ge. x(m)) then
            id = m
         else
            n2 = m
         endif
         if ((n2 - id) .eq. 1) return
      enddo
end subroutine nidentll

! File: testNidentll.f90
program testNidentll
  implicit none
  integer, parameter :: n = 5
  integer*8 :: x(n) = (/1, 3, 5, 7, 9/)
  integer*8 :: px
  integer :: id

  ! Test case 1: Element exists in the array
  px = 5
  call nidentll(x, px, n, id)
  print *, "Test 1 (Element exists): Expected 3, Got ", id

  ! Test case 2: Element does not exist, test insertion position
  px = 6
  call nidentll(x, px, n, id)
  print *, "Test 2 (Insert position): Expected 3, Got ", id

  ! Test case 3: Empty array
  call nidentll(x, px, 0, id)
  print *, "Test 3 (Empty array): Expected 0, Got ", id
end program testNidentll