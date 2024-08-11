program main
  implicit none
  integer :: a
  real :: result1, result2
  integer :: result3, result4

  a = 2

  ! Test functionality equivalent to m2
  call func_m2(a, result3)
  print *, "func_m2(2):", result3
  result1 = ent_m2(a)
  print *, "ent_m2(2):", result1

  ! Test functionality equivalent to m3
  call func_m3(a, result4)
  print *, "func_m3(2):", result4
  result2 = ent_m3(a)
  print *, "ent_m3(2):", result2

contains

  subroutine func_m2(a, func)
    implicit none
    integer, intent(in) :: a
    integer, intent(out) :: func
    func = a*8
  end subroutine func_m2

  function ent_m2(a) result(func2)
    implicit none
    integer, intent(in) :: a
    real :: func2
    func2 = -a*4.0
  end function ent_m2

  subroutine func_m3(a, res)
    implicit none
    integer, intent(in) :: a
    integer, intent(out) :: res
    res = a*12
  end subroutine func_m3

  function ent_m3(a) result(func2)
    implicit none
    integer, intent(in) :: a
    real :: func2
    func2 = -a*6.0
  end function ent_m3

end program main