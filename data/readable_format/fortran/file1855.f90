module para
contains
   function bobo(n)
       integer, intent(in) :: n
       character(len=(n)) :: bobo
       bobo = "1234567890"
   end function bobo
end module para

program test
   use para
   implicit none
   character(len=10) :: result

   ! Test 1: n = 5
   result = bobo(5)
   if (result(1:5) /= "12345") then
       print *, "Test 1 Failed"
   else
       print *, "Test 1 Passed"
   end if

   ! Test 2: n = 10
   result = bobo(10)
   if (result /= "1234567890") then
       print *, "Test 2 Failed"
   else
       print *, "Test 2 Passed"
   end if

   ! Test 3: n = 3
   result = bobo(3)
   if (result(1:3) /= "123") then
       print *, "Test 3 Failed"
   else
       print *, "Test 3 Passed"
   end if

end program test