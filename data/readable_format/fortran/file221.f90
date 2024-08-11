program main
   implicit none

   integer :: a(10000), b(10000)
   integer :: d

   a = 1
   b = 2
   a = a + b

   d = sum(a)

   print *, "Computed sum =", d
   call test_sum(d)

contains

   subroutine test_sum(computed_sum)
      integer, intent(in) :: computed_sum
      integer :: expected_sum

      expected_sum = 30000 ! Since 10000*(1+2)
      if (computed_sum == expected_sum) then
         print *, "Test passed: Computed sum is as expected."
      else
         print *, "Test failed: Computed sum does not match expected."
      end if
   end subroutine test_sum

end program main