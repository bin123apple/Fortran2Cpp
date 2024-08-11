program test_utemp
  implicit none
  integer :: msecpt, kstep, kinc, node, mi(2)
  real*8 :: temp(1), time(2), coords(3)
  real*8, allocatable :: vold(:,:)
  msecpt = 1
  kstep = 1
  kinc = 1
  node = 1
  mi = (/0, 5/)

  ! Assuming the size of the second dimension of vold is known for the test
  ! For demonstration, let's assume it needs to be 10
  allocate(vold(0:5, 10))

  call utemp_ccxlib(temp, msecpt, kstep, kinc, time, node, coords, vold, mi)

  if (temp(1) == 293.d0) then
    print *, "Test passed: temp(1) is correctly set to 293."
  else
    print *, "Test failed: temp(1) is not correctly set."
  endif

  ! Deallocate the vold array to free memory
  deallocate(vold)
end program test_utemp

! Dummy subroutine definition (to be replaced with actual subroutine)
subroutine utemp_ccxlib(temp, msecpt, kstep, kinc, time, node, coords, vold, mi)
  implicit none
  integer :: msecpt, kstep, kinc, node, mi(*)
  real*8 :: temp(msecpt), time(2), coords(3), vold(0:mi(2),*)
  temp(1) = 293.d0
end subroutine utemp_ccxlib