program test_typemod
  implicit none
  
  ! Define the type directly in the program
  type :: typemod
     real,    allocatable :: vp(:, :), vs(:, :), ro(:, :)
     real,    allocatable :: vpe(:, :), vse(:, :), roe(:, :)
     real,    allocatable :: bux(:, :), buz(:, :)
     real,    allocatable :: mu0(:, :), mue(:, :)
     real,    allocatable :: lb0(:, :), lbmu(:, :)
  end type typemod

  type(typemod) :: example
  
  ! Allocate arrays
  allocate(example%vp(10, 10))
  allocate(example%vs(10, 10))
  allocate(example%ro(10, 10))

  ! Example usage: Fill vp with values and print
  example%vp = 1.0
  print *, "vp(5,5) = ", example%vp(5,5)

  ! Deallocate arrays
  deallocate(example%vp)
  deallocate(example%vs)
  deallocate(example%ro)
  
end program test_typemod