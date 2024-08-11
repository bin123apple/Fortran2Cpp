module mymod
  implicit none
  type :: mytyp
    character(len=3) :: a = "XYZ"
  end type mytyp
end module mymod

program test_mymod
  use mymod
  implicit none
  
  type(mytyp) :: instance

  ! Test initialization of 'a'
  if (instance%a == "XYZ") then
    print *, "Test passed: 'a' correctly initialized to ", instance%a
  else
    print *, "Test failed: 'a' not correctly initialized, found ", instance%a
  endif
end program test_mymod