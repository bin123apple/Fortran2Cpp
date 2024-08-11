program prog
      implicit none
      character(len=6) :: buf
      integer :: num
      num = -2
      buf = 'AbCdEf'
      write(buf(2:4), '(i3)') num
      write(*, '(A)') 'num = (' // trim(buf) // ')'
end program prog