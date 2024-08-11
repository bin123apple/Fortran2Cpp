module m1
  implicit none
  type :: t
  end type t

  contains

  subroutine s1(x, y)
    class(t), intent(out) :: x
    integer, intent(in) :: y
    print *, "s1 called with y =", y
  end subroutine s1

  subroutine s2(x, y)
    real, intent(out) :: x
    class(t), intent(in) :: y
    print *, "s2 called"
    x = 0.0  ! Example assignment
  end subroutine s2
end module m1

program test_m1
  use m1
  type(t) :: x
  real :: a
  integer :: y

  ! Test s1
  y = 5
  call s1(x, y)

  ! Test s2
  call s2(a, x)
end program test_m1