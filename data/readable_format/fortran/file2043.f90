module SfrDiversionModule
  implicit none
  
  type SfrDiversionType
     integer :: id
     real :: flowRate
  end type SfrDiversionType

contains

  subroutine addDiversion(list, id, flowRate)
    type(SfrDiversionType), intent(inout), allocatable :: list(:)
    integer, intent(in) :: id
    real, intent(in) :: flowRate
    type(SfrDiversionType), allocatable :: tempList(:)
    
    tempList = [list, SfrDiversionType(id, flowRate)]
    if (allocated(list)) then
      list = tempList
    else
      allocate(list(size(tempList)))
      list = tempList
    endif
  end subroutine addDiversion

  function findDiversionById(list, id) result(foundDiversion)
    type(SfrDiversionType), intent(in), allocatable :: list(:)
    integer, intent(in) :: id
    type(SfrDiversionType), allocatable :: foundDiversion
    integer :: i

    foundDiversion = SfrDiversionType(-1, -1.0)  ! Default to an invalid state
    do i = 1, size(list)
      if (list(i)%id == id) then
         foundDiversion = list(i)
         return
      endif
    end do
  end function findDiversionById

end module SfrDiversionModule

program testSfrDiversion
  use SfrDiversionModule
  implicit none

  type(SfrDiversionType), allocatable :: diversionList(:)
  type(SfrDiversionType) :: foundDiversion
  integer :: i

  ! Test adding diversions
  call addDiversion(diversionList, 1, 100.0)
  call addDiversion(diversionList, 2, 200.0)

  if (allocated(diversionList)) then
    if (size(diversionList) == 2) then
      print *, "Test passed: Correct number of diversions added."
    else
      print *, "Test failed: Incorrect number of diversions added."
    endif
  else
    print *, "Test failed: Diversion list not allocated."
  endif

  ! Test searching for a specific diversion by ID
  foundDiversion = findDiversionById(diversionList, 2)

  if (foundDiversion%id /= -1) then
    print *, "Test passed: Diversion with ID 2 found."
  else
    print *, "Test failed: Diversion with ID 2 not found."
  endif

end program testSfrDiversion