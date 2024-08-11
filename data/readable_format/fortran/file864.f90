module foo_mod
  implicit none
  private
  public :: foo, foo2

  type :: foo
    integer :: i
  contains
    procedure, pass :: doit
    procedure, pass :: getit
  end type foo

  type, extends(foo) :: foo2
    integer :: j
  contains
    procedure, pass :: doit => doit2
    procedure, pass :: getit => getit2
  end type foo2

contains
  subroutine doit(this)
    class(foo), intent(inout) :: this
    this%i = 1
  end subroutine doit

  function getit(this) result(res)
    class(foo), intent(in) :: this
    integer :: res
    res = this%i
  end function getit

  subroutine doit2(this)
    class(foo2), intent(inout) :: this
    this%i = 2
    this%j = 3
  end subroutine doit2

  function getit2(this) result(res)
    class(foo2), intent(in) :: this
    integer :: res
    res = this%j
  end function getit2

end module foo_mod

module bar_mod
  use foo_mod, only: foo
  implicit none
  private
  public :: bar

  type :: bar
    class(foo), allocatable :: a
  contains
    procedure, pass :: doit => doitbar
    procedure, pass :: getit => getitbar
  end type bar

contains
  subroutine doitbar(this)
    class(bar), intent(inout) :: this
    call this%a%doit()
  end subroutine doitbar

  function getitbar(this) result(res)
    class(bar), intent(in) :: this
    integer :: res
    res = this%a%getit()
  end function getitbar
end module bar_mod

program test_foo
  use foo_mod
  use bar_mod
  implicit none

  type(bar) :: b
  integer :: result

  ! Test for base class functionality
  allocate(foo :: b%a)
  call b%doit()
  result = b%getit()
  if (result /= 1) then
    print *, "Test failed for base class. Expected 1, got", result
    stop
  end if
  deallocate(b%a)

  ! Test for derived class functionality
  allocate(foo2 :: b%a)
  call b%doit()
  result = b%getit()
  if (result /= 3) then
    print *, "Test failed for derived class. Expected 3, got", result
    stop
  end if

  print *, "All tests passed."

end program test_foo