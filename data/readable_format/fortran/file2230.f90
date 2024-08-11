program test_unittest
  implicit none
  character (len = 7), target :: textt
  character (len = 7), pointer :: textp
  character (len = 5), pointer :: textp2
  integer :: error_code

  ! Test case 1: Initial length checks
  error_code = 0
  textp => textt
  textp2 => textt(1:5)
  if (len(textp) /= 7) error_code = 1
  if (len(textp2) /= 5) error_code = 2
  if (error_code /= 0) then
    print *, 'Test case 1 failed with error code', error_code
    stop
  end if

  ! Test case 2: String assignments and final length checks
  error_code = 0
  textp = 'aaaaaaa'
  textp2 = 'bbbbbbb'
  if (textp /= 'bbbbbaa') error_code = 3
  if (textp2 /= 'bbbbb') error_code = 4
  if (error_code /= 0) then
    print *, 'Test case 2 failed with error code', error_code
    stop
  end if

  print *, 'All tests passed successfully!'
end program test_unittest