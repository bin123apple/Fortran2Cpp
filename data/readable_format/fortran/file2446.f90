module mytype_mod
  implicit none
  type :: mytype
    integer, allocatable :: indices(:)
  end type mytype
end module mytype_mod

program test_main
  use mytype_mod
  implicit none

  type(mytype) :: object
  integer :: i, me

  ! Assuming a parallel environment setup similar to Coarrays
  ! For standalone tests, we'll simulate 'this_image()' with a fixed value
  me = 1 ! Normally, you'd get this from MPI or Coarray functionality

  ! Allocate and set indices array
  allocate(object%indices(me))
  object%indices = [(i, i = 1, me)]

  ! Perform checks
  if (size(object%indices) /= 1) then
    call abort()
  endif
  if (object%indices(1) /= 1) then
    call abort()
  endif

  print *, "Fortran Unit Test Passed Successfully."

end program test_main