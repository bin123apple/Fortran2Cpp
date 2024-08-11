module great_rsd_module
  implicit none
contains
  subroutine swap_integers(a, b)
    integer, intent(inout) :: a, b
    integer :: temp
    temp = a
    a = b
    b = temp
  end subroutine swap_integers

  subroutine swap_reals(a, b)
    real, intent(inout) :: a, b
    real :: temp
    temp = a
    a = b
    b = temp
  end subroutine swap_reals

  subroutine add_ten(a)
    integer, intent(inout) :: a
    a = a + 10
  end subroutine add_ten
end module great_rsd_module

program test
  use great_rsd_module
  implicit none
  integer :: i1 = 10, i2 = 20
  real :: r1 = 2.5, r2 = 7.5

  call swap_integers(i1, i2)
  print *, "After swap_integers: i1 =", i1, "i2 =", i2

  call swap_reals(r1, r2)
  print *, "After swap_reals: r1 =", r1, "r2 =", r2

  call add_ten(i1)
  print *, "After add_ten: i1 =", i1
end program test