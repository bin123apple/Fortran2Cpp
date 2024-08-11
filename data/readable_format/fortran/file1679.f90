module elements
  implicit none
  type :: element_type
     type(ele_numbering_type), pointer :: numbering
  end type element_type

  type :: ele_numbering_type
     integer, dimension(:,:), allocatable :: number2count
  end type ele_numbering_type
end module elements

module global_numbering
  use elements
  implicit none
contains
  function element_local_coords(element) result (coords)
    type(element_type), intent(in) :: element    
    real, dimension(:), allocatable :: coords

    allocate(coords(size(element%numbering%number2count, 1)))
    coords = 0.0 
  end function element_local_coords
end module global_numbering

program test
  use global_numbering
  use elements
  implicit none
  type (element_type) :: e
  type (ele_numbering_type), target :: ent
  real, dimension(:), allocatable :: test_coords
  logical :: all_tests_passed = .true.

  allocate (ent%number2count(2,2))
  ent%number2count = reshape([1, 2, 3, 4], shape(ent%number2count))
  e%numbering => ent

  ! Test 1: Check dynamic allocation and structure contents
  if (allocated(e%numbering%number2count)) then
    if (all(e%numbering%number2count == reshape([1, 2, 3, 4], [2, 2]))) then
        print *, "Test 1 Passed."
    else
        print *, "Test 1 Failed: Incorrect array contents."
        all_tests_passed = .false.
    endif
  else
    print *, "Test 1 Failed: Array not allocated."
    all_tests_passed = .false.
  endif

  ! Test 2: Check elementLocalCoords function
  test_coords = element_local_coords(e)
  if (size(test_coords) == 2 .and. all(test_coords == [0.0, 0.0])) then
    print *, "Test 2 Passed."
  else
    print *, "Test 2 Failed."
    all_tests_passed = .false.
  endif

  if (all_tests_passed) then
    print *, "All tests passed."
  else
    print *, "Some tests failed."
  endif

end program test