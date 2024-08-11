module myModule
  implicit none
  contains

  real function e1(x)
    real, intent(in) :: x
    e1 = x * 3.0
  end function e1

  subroutine e2(a, b)
    real, intent(inout) :: a
    real, intent(in) :: b
    a = a + b
  end subroutine e2
end module myModule

program test
  use myModule
  implicit none

  real :: result
  real :: c

  ! Test e1 function
  result = e1(2.0)
  if (abs(result - 6.0) > 0.01) then
     print *, 'Test e1 failed'
  else
     print *, 'Test e1 passed'
  end if

  ! Test e2 subroutine
  c = 1.0
  call e2(c, 2.0)
  if (abs(c - 3.0) > 0.01) then
     print *, 'Test e2 failed'
  else
     print *, 'Test e2 passed'
  end if
end program test