module mod_t
  implicit none
  type :: t
    integer :: x
  end type t

contains
  logical function t_foo(this, other)
    class(t), intent(in) :: this, other
    t_foo = .false.
  end function t_foo

  logical function t_bar(this, other)
    class(t), intent(in) :: this, other
    t_bar = .false.
  end function t_bar
end module mod_t

program test_mod_t
  use mod_t
  implicit none

  type(t) :: obj1, obj2
  logical :: result

  obj1%x = 5
  obj2%x = 10

  ! Test t_foo function
  result = t_foo(obj1, obj2)
  print *, "Testing t_foo: ", .NOT. result

  ! Test t_bar function
  result = t_bar(obj1, obj2)
  print *, "Testing t_bar: ", .NOT. result

end program test_mod_t