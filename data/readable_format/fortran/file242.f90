program test_intrinsic_merge
   implicit none
   integer, dimension(3) :: a, b
   integer :: i
   logical, dimension(3) :: condition

   ! Test setup
   a = (/-1, 2, 3/)
   b = (/0, 0, 0/)

   ! Test 1: merge with i > 3
   i = 5
   if (merge(-1, 1, i > 3) /= -1) then
      print *, "Test 1 failed"
   else
      print *, "Test 1 passed"
   end if

   ! Test 2: merge with i >= 3
   i = 1
   if (merge(-1, 1, i >= 3) /= 1) then
      print *, "Test 2 failed"
   else
      print *, "Test 2 passed"
   end if

   ! Test 3: merge arrays based on a condition
   condition = a >= 0
   b = merge(a, 0, condition)
   if (all(b == (/0, 2, 3/))) then
      print *, "Test 3 passed"
   else
      print *, "Test 3 failed"
   end if
end program test_intrinsic_merge