module SMConstants
  implicit none
  integer, parameter :: RP = selected_real_kind(15, 307)  ! Define the kind parameter for real numbers
end module SMConstants

module RealDataLinkedList
  use SMConstants
  implicit none

  private
  public :: RealDataLinkedList_t, RealData_t

  type, public :: RealDataLinkedList_t
    type(RealData_t), pointer :: head => NULL()
    integer :: no_of_entries = 0
  contains
    procedure :: Append => RealDataLinkedList_Append
    procedure :: Load => RealDataLinkedList_Load
  end type RealDataLinkedList_t

  type, public :: RealData_t
    real(kind=RP) :: value
    type(RealData_t), pointer :: next => NULL()
  end type RealData_t

contains

  subroutine RealDataLinkedList_Append(self, value)
    class(RealDataLinkedList_t), intent(inout) :: self
    real(kind=RP), intent(in) :: value
    type(RealData_t), pointer :: current

    if (.not. associated(self%head)) then
      allocate(self%head)
      self%head%value = value
      self%no_of_entries = 1
    else
      current => self%head
      do while (associated(current%next))
        current => current%next
      end do
      allocate(current%next)
      current%next%value = value
      self%no_of_entries = self%no_of_entries + 1
    end if
  end subroutine RealDataLinkedList_Append

  subroutine RealDataLinkedList_Load(self, array)
    class(RealDataLinkedList_t), intent(in) :: self
    real(kind=RP), allocatable, intent(out) :: array(:)
    type(RealData_t), pointer :: current
    integer :: i

    if (self%no_of_entries > 0) then
      allocate(array(1:self%no_of_entries))
      current => self%head
      do i = 1, self%no_of_entries
        array(i) = current%value
        current => current%next
      end do
    end if
  end subroutine RealDataLinkedList_Load

end module RealDataLinkedList

! The main program to test the RealDataLinkedList
program TestRealDataLinkedList
  use SMConstants
  use RealDataLinkedList
  implicit none

  type(RealDataLinkedList_t) :: list
  real(kind=RP), allocatable :: array(:)

  ! Append data to the list
  call list%Append(1.0_RP)
  call list%Append(2.0_RP)
  call list%Append(3.0_RP)

  ! Load data from the list into an array
  call list%Load(array)

  ! Output the loaded data to verify the correctness
  print *, "List contents:"
  print *, array

end program TestRealDataLinkedList