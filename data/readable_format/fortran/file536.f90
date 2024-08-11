module foo_mod
  implicit none

  type, public :: foo
  contains
    procedure :: bar => base_bar
  end type foo

  type, extends(foo), public :: extfoo
  contains
    procedure :: bar => derived_bar
  end type extfoo

contains

  subroutine base_bar(this, j)
    class(foo), intent(inout) :: this
    integer, intent(in) :: j
    print *, "In base_bar with j=", j
  end subroutine base_bar

  subroutine derived_bar(this, j)
    class(extfoo), intent(inout) :: this
    integer, intent(in) :: j
    print *, "In derived_bar with j=", j
  end subroutine derived_bar

end module foo_mod

program test_foo_extfoo
  use foo_mod
  implicit none

  type(foo) :: aFoo
  type(extfoo) :: aExtFoo
  integer :: j

  ! Testing the base class method
  j = 10
  call aFoo%bar(j)

  ! Testing the derived class method
  j = 20
  call aExtFoo%bar(j)
end program test_foo_extfoo