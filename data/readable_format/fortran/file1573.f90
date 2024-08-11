module module_cells
  implicit none
  integer, allocatable, dimension(:,:) :: cells
end module module_cells

program test_module_cells
  use module_cells
  implicit none

  ! Allocate the cells array with dimensions 5x10.
  allocate(cells(5, 10))

  ! Set a value in the cells array.
  cells(3, 4) = 42

  ! Check if the value is correctly set.
  if (cells(3, 4) == 42) then
    print *, "Test passed: cells(3, 4) == 42"
  else
    print *, "Test failed: cells(3, 4) != 42"
  end if

  ! Deallocate the cells array to free the allocated memory.
  deallocate(cells)

end program test_module_cells