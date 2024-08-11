program test_foo
   implicit none
   call p1
   call q1
   print *, "All subroutines executed successfully."
end program test_foo

subroutine p1
   complex :: c5
   complex :: c6
   c5 = (c5)
   c6 = c6
end subroutine p1

subroutine q1
   real :: r5
   real :: r6
   r5 = (r5)
   r6 = r6
end subroutine q1