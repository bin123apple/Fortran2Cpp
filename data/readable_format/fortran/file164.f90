module types
  implicit none

  type, abstract :: base_t
     integer :: i = 0
   contains
     procedure(base_write_i_intf), deferred, pass :: write_procptr
     procedure :: write_i => base_write_i
  end type base_t

  abstract interface
    subroutine base_write_i_intf(this)
      import :: base_t
      class(base_t), intent(in) :: this
    end subroutine base_write_i_intf
  end interface

  type, extends(base_t) :: t
  contains
    procedure, pass :: write_procptr => extended_write_i
  end type t

contains

  subroutine base_write_i(this)
    class(base_t), intent(in) :: this
    print *, "Base write_i: ", this%i
  end subroutine base_write_i

  subroutine extended_write_i(this)
    class(t), intent(in) :: this
    print *, "Extended write_i: ", this%i
  end subroutine extended_write_i

end module types

program main
  use types
  implicit none

  class(base_t), allocatable :: obj
  type(t) :: obj_ext

  ! Use of the extended type 't'
  obj_ext%i = 3
  call obj_ext%write_i
  call obj_ext%write_procptr

  ! Demonstrating polymorphism
  allocate(t :: obj)
  obj%i = 5
  call obj%write_i
  call obj%write_procptr

end program main