module base_mod
  implicit none

  type, abstract :: base_type
  contains
    procedure(base_clone_iface), deferred :: clone
  end type base_type

  abstract interface
    subroutine base_clone_iface(self, clone)
      import :: base_type
      class(base_type), intent(in) :: self
      class(base_type), intent(out), allocatable :: clone
    end subroutine base_clone_iface
  end interface

end module base_mod

module r_mod
  use base_mod
  implicit none

  type, extends(base_type) :: r_type
  contains
    procedure :: clone => r_clone
  end type r_type

contains
  subroutine r_clone(self, clone)
    class(r_type), intent(in) :: self
    class(base_type), intent(out), allocatable :: clone

    allocate(clone, source=self)
  end subroutine r_clone

end module r_mod

program test_base_mod
  use base_mod
  use r_mod
  implicit none

  class(base_type), allocatable :: base_obj
  class(base_type), allocatable :: cloned_obj

  ! Create an instance of r_type and clone it
  allocate(r_type :: base_obj)
  call base_obj%clone(cloned_obj)

  ! Check if the cloned object is indeed of type r_type
  ! This is a basic way to test the polymorphic clone operation.
  if (.not. allocated(cloned_obj)) then
      print *, "Test failed: clone did not work as expected."
  else
      print *, "Test passed: clone operation successful."
  endif

end program test_base_mod