program testStringLength
  implicit none
  integer, parameter :: expected_length = 5
  integer :: actual_length
  character(len=10) :: testString

  testString = "Hello"
  actual_length = len_trim(testString)

  call testLength(actual_length, expected_length)
end program testStringLength

subroutine testLength(actual_length, expected_length)
  implicit none
  integer, intent(in) :: actual_length, expected_length

  if (actual_length == expected_length) then
     print *, "Fortran Test PASSED."
  else
     print *, "Fortran Test FAILED."
  end if
end subroutine testLength