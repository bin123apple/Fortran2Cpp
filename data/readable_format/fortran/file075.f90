module bar
  implicit none
  private
  public :: bar_type

  type, abstract :: bar_type
  contains
    procedure(bar_test_interface), deferred :: test_method
  end type bar_type

  abstract interface
    subroutine bar_test_interface(this)
      import :: bar_type
      class(bar_type), intent(in) :: this
    end subroutine bar_test_interface
  end interface

end module bar

module foo
  use bar, only: bar_type
  implicit none
  private
  public :: foo_type

  type, extends(bar_type) :: foo_type
  contains
    procedure :: test_method
  end type foo_type

contains

  subroutine test_method(this)
    class(foo_type), intent(in) :: this
    print *, "foo_type test method called"
  end subroutine test_method

end module foo

program test_program
  use foo, only: foo_type
  implicit none

  type(foo_type) :: example

  call example%test_method()

end program test_program