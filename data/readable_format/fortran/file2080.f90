program testPrintFormatted
  implicit none
  integer :: ii
  integer, parameter :: expected = 10

  ii = 10
  call testValue(ii, expected)

contains

  subroutine testValue(value, expected)
    integer, intent(in) :: value, expected
    if (value == expected) then
      print *, "Test passed."
    else
      print *, "Test failed: Value is ", value, " but expected ", expected
    endif
  end subroutine testValue

end program testPrintFormatted