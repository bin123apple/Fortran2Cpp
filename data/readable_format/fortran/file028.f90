program test
  implicit none
  integer :: status
  
  ! Call the subroutine to perform the test
  call one(status)
  
  ! Check the returned status for success or failure
  if (status == 0) then
    print *, "Allocation successful."
  else
    print *, "Allocation failed with status: ", status
  endif
contains
  subroutine one(status)
    implicit none
    integer, allocatable :: a(:,:,:)
    integer :: status
    integer :: lb1, ub1, lb2, ub2, lb3, ub3
    
    ! Define bounds
    lb1 = -4; ub1 = 9
    lb2 = 1; ub2 = 8
    lb3 = 1; ub3 = 4
    
    ! Attempt to allocate the array
    allocate(a(lb1:ub1, lb2:ub2, lb3:ub3), stat=status)
  end subroutine one
end program test