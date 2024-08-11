program main
implicit none

! Test the functionality
call test(.true.)
call test(.false.)

contains

! Function to test
integer function hello()
 hello = 42
end function hello

! Subroutine that uses the hello function and performs simple checks
subroutine test(first)
 logical :: first
 integer :: i
 procedure(integer), pointer :: x => null()

 if(first) then
  ! Ensure x is not associated
  if(associated(x)) then
   print *, "Test failed: x should not be associated."
   call abort()
  endif
  x => hello
 else
  ! Ensure x is associated
  if(.not. associated(x)) then
   print *, "Test failed: x should be associated."
   call abort()
  endif
  i = x()
  ! Check if i equals 42
  if(i /= 42) then
   print *, "Test failed: The return value of hello should be 42."
   call abort()
  endif
 end if
 print *, "Test passed."
end subroutine test

end program main