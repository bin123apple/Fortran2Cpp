! Example Fortran program with simple testable subroutines

subroutine f7(a, r)
  integer, intent(out) :: a
  real, intent(out) :: r
  a = 5
  r = 10.0
end subroutine f7

subroutine f9(i)
  integer, intent(out) :: i
  i = 1
end subroutine f9

subroutine f10(a, b)
  integer, intent(out) :: a, b
  a = 2
  b = 3
end subroutine f10

program test
  integer :: a, b, i
  real :: r
  
  call f7(a, r)
  print *, 'f7:', a, r
  
  call f9(i)
  print *, 'f9:', i
  
  call f10(a, b)
  print *, 'f10:', a, b
end program test