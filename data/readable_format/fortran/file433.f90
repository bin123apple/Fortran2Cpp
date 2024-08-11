program testIfElseIfElseProg
implicit none

   integer :: a
   integer, parameter :: testValues(4) = [10, 20, 30, 100]
   integer :: i

   do i = 1, size(testValues)
      a = testValues(i)
      if( a == 10 ) then
         a = a + 1
         print*, "Test for a=10 passed, a=", a
      else if( a == 20 ) then
         print*, "Value of a is 20 - Test Passed" 
      else if( a == 30 ) then
         print*, "Value of a is 30 - Test Passed" 
      else
         print*, "None of the values is matching - Test for a=", a, " Passed"
      end if
   end do

end program testIfElseIfElseProg