program test
   use ISO_C_BINDING
   implicit none
   type, bind(C) :: descr
      type(C_PTR) :: address
   end type descr
   type(descr) :: DD
   double precision, target :: buf(1)
   integer (C_INTPTR_T) :: i, j

   ! Test setup
   buf = (/ 0 /)
   DD = descr(c_loc(buf))
   i = transfer (DD%address, 0_c_intptr_t)
   j = transfer (c_loc(buf), 0_c_intptr_t)

   ! Test 1: Check if pointers are non-null
   if (any((/ i,j /) == 0_c_intptr_t)) then
      print *, "Test 1 Failed: Null pointer encountered."
      STOP 1
   else
      print *, "Test 1 Passed."
   end if

   ! Test 2: Check if pointers are equal
   if (i /= j) then
      print *, "Test 2 Failed: Pointers do not match."
      STOP 2
   else
      print *, "Test 2 Passed."
   end if

   print *, "All tests passed."
end program test