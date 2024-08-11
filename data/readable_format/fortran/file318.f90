module test_mod
  implicit none

  type, abstract :: t
  contains
    procedure(poly_interface), deferred :: display
  end type t

  abstract interface
    subroutine poly_interface(self)
      import :: t
      class(t), intent(in) :: self
    end subroutine poly_interface
  end interface

  type, extends(t) :: t_derived
  contains
    procedure :: display => display_derived
  end type t_derived

contains

  subroutine display_derived(self)
    class(t_derived), intent(in) :: self
    print *, "Display from derived class."
  end subroutine display_derived

  subroutine test()
    class(t), allocatable :: obj
    type(t_derived) :: derived_obj

    allocate(t_derived :: obj)
    call obj%display()
  end subroutine test

end module test_mod

program main
  use test_mod
  call test()
end program main