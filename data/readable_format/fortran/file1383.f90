module phs_single

  implicit none

  type :: phs_single_t
   contains
     procedure, nopass :: d1
     procedure, nopass :: d2
  end type phs_single_t

contains

  function d1() result(res)
    real :: res(2)
    res = 1.
  end function d1

  function d2(n) result(res)
    integer, intent(in) :: n
    real :: res(n)
    res = 1.
  end function d2

end module phs_single

program test_phs_single
  use phs_single
  implicit none

  type(phs_single_t) :: phs
  real :: test_result(2)

  ! Testing d1
  test_result = phs%d1()
  print *, "Testing d1: ", test_result

  ! Testing d2
  test_result = phs%d2(2)
  print *, "Testing d2 with n=2: ", test_result

end program test_phs_single