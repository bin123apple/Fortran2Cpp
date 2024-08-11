program main
  implicit none
  integer, parameter :: N = 1000
  integer :: a(N), sa, result, i
  real(4) :: b(N), sb
  real(8) :: c(N), sc

  do i=1, N
     if(mod(i,100).eq.0) then
        a(i) = 2
        b(i) = 2.0
        c(i) = 4.0
     else if(mod(i,100).eq.50) then
        a(i) = 1
        b(i) = 0.5
        c(i) = 0.25
     else
        a(i) = 1
        b(i) = 1.0
        c(i) = 1.0
     endif
  enddo

  sa = 1
  sb = 1.0
  sc = 1.0

  do i=1, N
     sa = sa * a(i)
     sb = sb * b(i)
     sc = sc * c(i)
  enddo

  result = 0
  if( sa /= 1024 .or. abs(sb-1.0) > 0.0000001 .or. abs(sc-1.0) > 0.0001 ) then
     result = -1
  endif

  if( result == 0 ) then
     print *, "PASS"
  else
     print *, "ERROR"
  endif
end program main