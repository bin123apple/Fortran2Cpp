module matrix_mod
  implicit none
  public :: Matrix, initialize_matrix

  type :: Matrix
     integer :: rows
     integer :: columns
     real, allocatable :: data(:,:)
  end type Matrix

contains

  subroutine initialize_matrix(this, rows, columns)
    class(Matrix), intent(inout) :: this
    integer, intent(in) :: rows, columns

    this%rows = rows
    this%columns = columns
    allocate(this%data(rows, columns))
  end subroutine initialize_matrix

end module matrix_mod

program test_matrix
  use matrix_mod
  implicit none

  type(Matrix) :: mat
  integer :: test_rows, test_columns
  logical :: allocation_success

  ! Test 1: Initialize and allocate a matrix with specific dimensions
  test_rows = 5
  test_columns = 10
  call initialize_matrix(mat, test_rows, test_columns)

  allocation_success = allocated(mat%data)
  if (.not. allocation_success) then
    print *, "Test 1 Failed: Data array not allocated."
  else
    if (mat%rows == test_rows .and. mat%columns == test_columns) then
      print *, "Test 1 Passed: Matrix initialized and allocated correctly."
    else
      print *, "Test 1 Failed: Matrix dimensions incorrect."
    endif
  endif

  ! Cleanup: Deallocate the allocated array
  if (allocated(mat%data)) then
    deallocate(mat%data)
  endif

end program test_matrix