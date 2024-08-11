program test_shiftz
  implicit none
  integer :: nsp, i
  real :: dw
  complex, allocatable :: spec(:), z(:)
  
  ! Initialize test variables
  nsp = 3
  dw = 0.5
  
  allocate(spec(nsp))
  allocate(z(nsp))
  
  ! Assign test values to spec array
  spec(1) = cmplx(1.0, 2.0)
  spec(2) = cmplx(3.0, 4.0)
  spec(3) = cmplx(5.0, 6.0)
  
  ! Call the subroutine
  call shiftz(spec, nsp, dw, z)
  
  ! Print results for verification
  print *, "spec: ", spec
  print *, "z: ", z
  
  ! Deallocate arrays
  deallocate(spec)
  deallocate(z)
  
end program test_shiftz

subroutine shiftz(spec,nsp,dw,z)
  implicit none
  integer, intent(in) :: nsp
  real, intent(in) :: dw
  complex, intent(inout) :: spec(nsp)
  complex, intent(out) :: z(nsp)
  integer :: i

  do i = 1, nsp
    z(i) = spec(i) * cmplx(cos(dw), sin(dw))
  end do
end subroutine shiftz