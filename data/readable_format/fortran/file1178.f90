program test
  implicit none
  complex :: cresult, cexpected
  real :: re, im
  integer :: error_count
  
  error_count = 0
  
  ! Example test for complex power
  re = 2.0
  im = -4.3
  cexpected = cmplx(2.0, -4.3)**2
  cresult = cmplx(-14.49, -17.2) ! Assuming this is the expected calculation result
  call assert_complex_equals(cresult, cexpected, error_count, "Complex power")
  
  if (error_count == 0) then
    print *, "All tests passed."
  else
    print *, "There were ", error_count, " errors."
  endif

contains

  subroutine assert_complex_equals(a, b, error_count, message)
    complex, intent(in) :: a, b
    integer, intent(inout) :: error_count
    character(len=*), intent(in) :: message
    real :: diff
    diff = abs(a - b)
    if (diff > 1.0E-5) then
      print *, "Test failed for complex: ", a, " /= ", b, ". Test: ", trim(message)
      error_count = error_count + 1
    endif
  end subroutine assert_complex_equals

end program test