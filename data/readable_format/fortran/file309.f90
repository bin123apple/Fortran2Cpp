module my_module
  implicit none
contains
  elemental function fn(x, y) result(concatenated)
    character(len=*), intent(in) :: x, y
    character(len=128) :: concatenated

    concatenated = trim(x) // y
  end function fn
end module my_module

program test_fn_function
  use my_module
  implicit none
  character(len=64) :: x, y
  character(len=128) :: result

  x = "Hello"
  y = "World"
  result = fn(x, y)

  if (trim(result) /= "HelloWorld") then
    print *, 'Test Failed: fn function - Expected "HelloWorld", got "', trim(result), '"'
  else
    print *, 'Test Passed: fn function'
  endif

end program test_fn_function