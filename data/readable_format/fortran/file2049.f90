program test_p
  character(:), allocatable :: z(:)
  integer :: test_result
  z = [character(2):: 'ab', 'xy']
  z = z(2)
  if (any(z /= 'xy')) then
    test_result = 1
  else
    test_result = 0
  endif
  print *, "Test Result:", test_result
end program test_p