program testPrintFormatted
  implicit none
  integer :: ii
  ii = 10
  call testVariable(ii)
contains
  subroutine testVariable(value)
    integer, intent(in) :: value
    if (value == 10) then
      print *, "Test Passed: ii is correctly assigned the value 10."
    else
      print *, "Test Failed: ii is not correctly assigned the value 10."
    endif
  end subroutine testVariable
end program testPrintFormatted