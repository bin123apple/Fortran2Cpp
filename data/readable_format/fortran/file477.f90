program array_char
  implicit none
  integer :: i, j(5)
  character (len=5) :: x, y
  character (len=5) :: z(2)
  x = "ab"
  y = "cd"
  z = (/y(1: len(trim(y))), x(1: len(trim(x)))/)
  j = ichar([(z(1)(i:i), i=1,5)])
  if (any(j .ne. (/99,100,32,32,32/))) STOP 1
  j = ichar([(z(2)(i:i), i=1,5)])
  if (any(j .ne. (/97,98,32,32,32/))) STOP 2
  x = "a "
  z = (/y(1: len(trim(y))), x(1: len(trim(x)))/)
end program array_char