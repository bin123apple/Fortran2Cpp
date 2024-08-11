! main.f90
module particle_mod
  implicit none
  TYPE :: particle_type
    INTEGER, ALLOCATABLE :: p(:)
  END TYPE particle_type
end module particle_mod

program main
  use particle_mod
  implicit none
  TYPE(particle_type), ALLOCATABLE :: t(:)
  integer :: i
  logical :: f

  i = 1
  allocate(t(1))
  allocate(t(1)%p(0))  ! Allocating an array of size 0
  f = allocated(t(i)%p)  ! Check if t(i)%p is allocated

  ! Output to check
  if (f) then
    print *, "Test passed: t(i)%p is allocated."
  else
    print *, "Test failed: t(i)%p is not allocated."
  endif
end program main