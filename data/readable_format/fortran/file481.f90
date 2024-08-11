program testBanner
  implicit none

  call banner(2023, 4, 15)

end program testBanner

subroutine banner(ivery, iverm, iverd)
  implicit none
  integer :: ivery, iverm, iverd

  write(*,101)
  write(*,102)
  write(*,103) ivery, iverm, iverd
  write(*,101)
  write(*,104)

101 format('********************************************************')
102 format('******************       GOTIC2       ******************')
103 format('****************** Version ',i4,'.',i2.2,'.',i2.2, &
     ' ******************')
104 format(' ')

end subroutine banner