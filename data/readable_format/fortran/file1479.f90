program test_f
  implicit none
  integer :: expected, result
  
  expected = 88
  result = f()
  
  if (result == expected) then
    print *, "Test passed: f() = ", result
  else
    print *, "Test failed: f() = ", result, ", expected: ", expected
  end if

contains

  elemental integer function f()
    f = 88
  end function f

end program test_f