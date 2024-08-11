program testProgram
  implicit none

  integer(kind=1) :: i1
  integer(kind=2) :: i2
  integer(kind=4) :: i4
  integer(kind=8) :: i8
  real(kind=8) :: r
  character(len=2) :: s1, s2

  i1 = 1 ; i2 = 1 ; i4 = 1 ; i8 = 1
  r = 1.0
  s1 = '42'
  
  s2 = repeat(s1,i1)
  if (s2 /= s1) call report_error(1)
  s2 = repeat(s1,i2)
  if (s2 /= s1) call report_error(2)
  s2 = repeat(s1,i4)
  if (s2 /= s1) call report_error(3)
  s2 = repeat(s1,i8)
  if (s2 /= s1) call report_error(4)

  print *, "All tests passed successfully."

contains
  subroutine report_error(errorCode)
    integer, intent(in) :: errorCode
    print *, "Test failed with error code: ", errorCode
    stop
  end subroutine report_error

end program testProgram