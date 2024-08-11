program bug20_test

  implicit none

  type :: d_base_sparse_mat
    integer :: v(10) = 0
  end type d_base_sparse_mat

  type(d_base_sparse_mat), allocatable :: a
  integer :: expected_size, actual_size

  ! Allocate and initialize 'a'
  allocate (d_base_sparse_mat :: a)

  ! Test: Check the size of array 'v' in 'a'
  expected_size = 10
  actual_size = size(a%v)

  if (actual_size == expected_size) then
    write(*,*) 'Test Passed: Array size check.'
  else
    write(*,*) 'Test Failed: Array size check. Expected:', expected_size, 'Got:', actual_size
    stop 1
  end if

end program bug20_test