module Members
  implicit none

  type HasMembers
    integer :: kind_member
    integer :: len_member
    integer :: member
  contains
    procedure :: MyMethod
  end type HasMembers

contains

  subroutine MySubroutine(arg)
    integer :: arg  ! Assuming arg should be an integer
    ! This subroutine does nothing for now, just a placeholder for arg
    print *, 'MySubroutine called with arg =', arg
  end subroutine MySubroutine
  
  subroutine MyMethod(this)
    class(HasMembers), intent(in) :: this
    print *, 'Member value:', this%member
  end subroutine MyMethod

end module Members

program test
  use Members
  implicit none

  type(HasMembers) :: obj

  ! Initialize the object
  obj%kind_member = 1
  obj%len_member = 10
  obj%member = 5

  ! Test the method
  call obj%MyMethod()

  ! Test MySubroutine with a dummy argument
  call MySubroutine(10)

end program test