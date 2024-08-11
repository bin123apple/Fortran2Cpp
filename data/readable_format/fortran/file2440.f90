module mathlib
  implicit none
  
  private
  public :: add, sub, mul, div, md

contains
  pure function add(lhs, rhs) result(res)
    integer, intent(in) :: lhs, rhs
    integer :: res
    res = lhs + rhs
  end function add

  pure function sub(lhs, rhs) result(res)
    integer, intent(in) :: lhs, rhs
    integer :: res
    res = lhs - rhs
  end function sub

  pure function mul(lhs, rhs) result(res)
    integer, intent(in) :: lhs, rhs
    integer :: res
    res = lhs * rhs
  end function mul

  pure function div(lhs, rhs) result(res)
    integer, intent(in) :: lhs, rhs
    integer :: res
    res = lhs / rhs
  end function div

  pure function md(lhs, rhs) result(res)
    integer, intent(in) :: lhs, rhs
    integer :: res
    res = mod(lhs, rhs)
  end function md
end module mathlib

program test_mathlib
  use mathlib
  implicit none

  integer :: a, b

  a = 10
  b = 3

  print *, "Testing add: ", add(a, b)  ! Expected: 13
  print *, "Testing sub: ", sub(a, b)  ! Expected: 7
  print *, "Testing mul: ", mul(a, b)  ! Expected: 30
  print *, "Testing div: ", div(a, b)  ! Expected: 3
  print *, "Testing mod: ", md(a, b)   ! Expected: 1

end program test_mathlib