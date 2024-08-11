program bug_test
  implicit none
  integer, dimension(1) :: i
  i(:) = 1
  call foo(i)
  
  ! Test if the subroutine works as expected
  if (i(1) == 2) then
    print *, 'Test Passed: i(1) is correctly set to 2.'
  else
    print *, 'Test Failed: i(1) is not 2.'
  endif

contains
  subroutine foo(v)
    integer, dimension(*) :: v
    v(1) = 2
  end subroutine foo
end program bug_test