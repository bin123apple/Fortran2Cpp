module test_module
  implicit none

  type, public :: test_p
    private
    class (test_p), pointer :: next => null()

  contains
    procedure :: is_next_associated
  end type test_p

  type, public :: test
    class (test), pointer :: next => null()
  end type test

contains

  subroutine do_it(x)
    class (test_p), target :: x
    x%next => x
  end subroutine do_it

  ! New method to check if next is associated with self
  logical function is_next_associated(self) result(assoc)
    class(test_p), target :: self
    assoc = associated(self%next, self)
  end function is_next_associated

end module test_module

program test_program
  use test_module
  implicit none

  class(test_p), pointer :: x

  ! Setup
  allocate(x)
  call do_it(x)

  ! Test to see if x%next is associated with x (simple test)
  if (x%is_next_associated()) then
    print *, "Test passed: x%next is associated with x."
  else
    print *, "Test failed: x%next is not associated with x."
  endif

  ! Teardown
  deallocate(x)
end program test_program