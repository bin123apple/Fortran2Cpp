module mmm
  integer :: j
end module mmm

program test_mmm
  use mmm
  implicit none

  ! Initialize the variable
  j = 5

  ! Check the value of j and print the result
  if (j == 5) then
    print *, 'Test passed: j == 5'
  else
    print *, 'Test failed: j /= 5'
  end if
end program test_mmm