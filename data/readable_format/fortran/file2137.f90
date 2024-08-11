module Enums
  implicit none
  real :: somevar = 0.0
  real, parameter :: othervar = 42.0

  enum, bind(c)
     enumerator :: red = 1, blue, gold, silver, bronze, purple
  end enum

contains

  function Func(arg) result(res)
    real, intent(in) :: arg
    real :: res
    res = arg
  end function Func

end module Enums

program TestEnums
  use Enums
  implicit none

  ! Variables for testing
  real :: test_var
  real :: func_result

  somevar = 3.14
  test_var = somevar
  if (test_var == 3.14) then
    print *, "Test passed: somevar"
  else
    print *, "Test failed: somevar"
  end if

  if (othervar == 42.0) then
    print *, "Test passed: othervar"
  else
    print *, "Test failed: othervar"
  end if

  func_result = Func(2.71)
  if (func_result == 2.71) then
    print *, "Test passed: Func"
  else
    print *, "Test failed: Func"
  end if
end program TestEnums