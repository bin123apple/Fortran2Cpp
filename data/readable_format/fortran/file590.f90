! char_pointer_comp_assign_test.f90
program test_char_pointer_comp_assign
  implicit none

  type :: dt
     character (len=4), pointer :: scalar
     character (len=4), pointer :: array(:)
  end type dt

  type(dt) :: a
  character(len=4), target :: scalar_t = "abcd"
  character(len=4), target :: array_t(2) = (/"abcd", "efgh"/)

  ! Test 1: Scalar pointer assignment and comparison
  allocate(a%scalar)
  a%scalar = scalar_t
  if (a%scalar == "abcd") then
     print *, "Test 1 Passed: Scalar comparison successful."
  else
     print *, "Test 1 Failed: Scalar comparison failed."
  end if
  deallocate(a%scalar)

  ! Test 2: Array pointer assignment and comparison
  allocate(a%array(2))
  a%array = array_t
  if (all(a%array == (/"abcd", "efgh"/))) then
     print *, "Test 2 Passed: Array comparison successful."
  else
     print *, "Test 2 Failed: Array comparison failed."
  end if
  deallocate(a%array)

end program test_char_pointer_comp_assign

! Compile and run this Fortran program using your Fortran compiler.
! Example using gfortran:
! gfortran char_pointer_comp_assign_test.f90 -o test
! ./test