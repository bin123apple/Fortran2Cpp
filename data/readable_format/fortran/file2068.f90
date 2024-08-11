module spec_min_module
  implicit none
contains
  double precision function spec_min(spec, nspec, nchannel, npnts)
    implicit none
    double precision, intent(in) :: spec(:,:,:)
    integer, intent(in) :: nspec, nchannel, npnts
    integer :: i

    spec_min = spec(nspec, nchannel, 1)
    do i = 2, npnts
       if (spec(nspec, nchannel, i) < spec_min) then
          spec_min = spec(nspec, nchannel, i)
       endif
    end do
  end function spec_min
end module spec_min_module

program test_spec_min
  use spec_min_module
  implicit none
  double precision, allocatable :: spec(:,:,:)
  double precision :: result
  integer :: i, j, k
  integer :: nspec, nchannel, npnts

  ! Define dimensions
  nspec = 1
  nchannel = 1
  npnts = 10

  ! Allocate and initialize the 3D array
  allocate(spec(1,1,npnts))
  do k = 1, npnts
     spec(1,1,k) = k * 1.0  ! Simple initialization for testing
  enddo

  ! Introduce a known minimum value
  spec(1,1,5) = -1.0

  ! Call the function
  result = spec_min(spec, nspec, nchannel, npnts)

  ! Print the result
  print *, "The minimum value in the specified slice is: ", result

  ! Deallocate the array
  deallocate(spec)
end program test_spec_min