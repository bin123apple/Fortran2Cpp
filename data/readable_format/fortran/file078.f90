! testStringAllocation.f90
program testStringAllocation
  implicit none
  character(len=:), allocatable :: s
  integer :: i=10

  ! Allocate the string
  allocate(character(len=i)::s)
  
  ! Test: Check the length of the string
  if (len(s) == i) then
     print *, "Fortran Test passed."
  else
     print *, "Fortran Test failed."
  end if
end program testStringAllocation