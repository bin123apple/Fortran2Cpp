program test_stlest
  implicit none
  double precision h
  call test_case(5, 10, h)
  call test_case(15, 2, h)
  call test_case(7, 7, h)
end program test_stlest

subroutine test_case(nleft, nright, h)
  integer nleft, nright
  double precision h
  call stlest(nleft, nright, h)
  print *, 'nleft:', nleft, 'nright:', nright, 'h:', h
end subroutine test_case

subroutine stlest(nleft, nright, h)
  integer nleft, nright
  double precision h
  h = max(dble(nleft), dble(nright))
end subroutine stlest