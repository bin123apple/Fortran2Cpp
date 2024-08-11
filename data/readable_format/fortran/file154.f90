module NoBindMod
  use iso_c_binding
  implicit none

  public :: NoBindSub1, Func1, Func2, Func3

contains

  subroutine NoBindSub1(int1, double1, double2, int2) 
    integer(kind=c_int)        :: int1(10)
    real(kind=c_double), intent(in)         :: double1
    real(kind=c_double), intent(in), dimension(10, 20, *)              :: double2
    integer             :: int2(:)
    ! Body of NoBindSub1
  end subroutine NoBindSub1

  function Func1() result(res)
    real(kind=c_double) :: res
    res = 0.0d0
  end function Func1

  function Func2() result(res)
    real(kind=c_double) :: res
    res = 0.0d0
  end function Func2

  function Func3() result(res)
    real(kind=c_double) :: res
    res = 0.0d0
  end function Func3

end module NoBindMod

program test
  use NoBindMod
  implicit none

  real(kind=c_double) :: result

  ! Test Func1
  result = Func1()
  if (result /= 0.0d0) then
    print *, "Func1 FAILED."
  else
    print *, "Func1 PASSED."
  endif

  ! Test Func2
  result = Func2()
  if (result /= 0.0d0) then
    print *, "Func2 FAILED."
  else
    print *, "Func2 PASSED."
  endif

  ! Test Func3
  result = Func3()
  if (result /= 0.0d0) then
    print *, "Func3 FAILED."
  else
    print *, "Func3 PASSED."
  endif

end program test