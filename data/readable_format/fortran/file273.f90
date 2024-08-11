program main
  call sub1
end program main

subroutine sub1
  real :: a(10)
  call sub2
  print *, "sub1 was called"
end subroutine sub1

subroutine sub2
  integer :: b(10)
  print *, "sub2 was called"
end subroutine sub2