program pr78757_test
  implicit none
  character (len = 30), target :: x
  character (len = 30), pointer :: s
  s => foo (30_8)
  
  x = ' '  ! Initialize x with spaces
  s = 'Test Successful'
  
  if (x == s) then
     print *, 'Test passed: ', x
  else
     print *, 'Test failed'
  endif

contains

  function foo (i)
    integer (8) :: i
    character (len = i), pointer :: foo
    foo => x
  end function foo
  
end program pr78757_test