module m1
  implicit none
  private
  public :: t

  type :: t
  contains
    procedure, pass(x) :: add1 => add
    procedure, nopass :: add2 => add
    procedure :: add_real
    generic :: g => add1, add2, add_real
  end type t

contains
  integer(8) function add(x, y)
    class(t), intent(in) :: x, y
    add = 1 ! Placeholder implementation
  end function add

  integer(8) function add_real(x, y)
    class(t), intent(in) :: x
    real, intent(in) :: y
    add_real = 2 ! Placeholder implementation
  end function add_real

end module m1

program test_m1
  use m1
  implicit none

  type(t) :: x, y
  real :: z
  integer(8) :: result

  ! Test add function
  result = x%add1(y)
  print *, "Result of add1: ", result

  ! Test add_real function
  result = x%add_real(3.0)
  print *, "Result of add_real: ", result

  ! Add more tests as needed
end program test_m1