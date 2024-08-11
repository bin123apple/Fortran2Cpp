program p_test
   implicit none
   real :: y(3), z(4)
   integer :: i
   logical :: test_passed

   y = 2.0 * [real :: 1, [2], 3]
   z = 2.0 * [real :: 1, [2, [4]], 3]

   test_passed = .true.

   if (any(y /= [2., 4., 6.])) then
      print *, "Test failed for y"
      test_passed = .false.
   endif

   if (any(z /= [2., 4., 8., 6.])) then
      print *, "Test failed for z"
      test_passed = .false.
   endif

   if (test_passed) then
      print *, "All tests passed."
   else
      print *, "Some tests failed."
   endif
end program p_test