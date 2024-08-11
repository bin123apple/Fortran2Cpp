module data_coarse
  implicit none

  public
  integer :: nc
  integer, dimension(:), allocatable :: iclev
  integer :: ns_ib
  integer, dimension(:), allocatable :: iclevc
end module data_coarse

program test_data_coarse
  use data_coarse
  implicit none

  integer :: i
  integer :: allocStatus

  ! Initialize module variables
  nc = 5
  ns_ib = 10

  ! Allocate and fill the allocatable arrays
  allocate(iclev(nc), stat=allocStatus)
  if (allocStatus /= 0) stop "Allocation error for iclev"
  allocate(iclevc(nc), stat=allocStatus)
  if (allocStatus /= 0) stop "Allocation error for iclevc"

  iclev = [(i, i=1,nc)]
  iclevc = [(i*2, i=1,nc)]

  ! Perform tests - simple printouts in place of formal unit tests
  print *, "nc should be 5: ", nc
  print *, "ns_ib should be 10: ", ns_ib
  print *, "iclev should be 1,2,3,4,5: ", iclev
  print *, "iclevc should be 2,4,6,8,10: ", iclevc

  ! Clean up
  deallocate(iclev)
  deallocate(iclevc)
end program test_data_coarse