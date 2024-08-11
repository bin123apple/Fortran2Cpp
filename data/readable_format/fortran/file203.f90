module linkedcells
  implicit none
  integer :: nboxesx, nboxesy, nboxesz
  double precision :: xmin, ymin, zmin, xmax, ymax, zmax
  integer, allocatable :: ifirstbox(:,:,:), inextbox(:)
end module linkedcells

program test_linkedcells
  use linkedcells
  implicit none

  integer :: nx, ny, nz, i

  ! Initialize module variables
  nboxesx = 3
  nboxesy = 3
  nboxesz = 3

  ! Allocate arrays based on the above dimensions
  allocate(ifirstbox(nboxesx, nboxesy, nboxesz))
  allocate(inextbox(nboxesx*nboxesy*nboxesz))

  ! Example manipulation: Fill arrays with test values
  do i = 1, size(inextbox)
      inextbox(i) = i
  end do

  ! Simple checks to verify functionality
  if (allocated(ifirstbox) .and. allocated(inextbox)) then
      print *, "Arrays allocated successfully."
  endif

  if (inextbox(size(inextbox)) == size(inextbox)) then
      print *, "inextbox test passed."
  else
      print *, "inextbox test failed."
  endif

  ! Clean up
  deallocate(ifirstbox)
  deallocate(inextbox)
end program test_linkedcells