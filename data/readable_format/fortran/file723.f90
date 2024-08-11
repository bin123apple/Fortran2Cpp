program test_bug23
  implicit none

  type :: psb_base_sparse_mat
    integer, allocatable :: irp(:)
  end type psb_base_sparse_mat

  class(psb_base_sparse_mat), allocatable :: a
  type(psb_base_sparse_mat) :: acsr
  integer :: i
  logical :: test_passed
  integer, dimension(4) :: expected_values

  expected_values = [1, 3, 4, 5]
  allocate(acsr%irp(4))
  acsr%irp = [1, 3, 4, 5]

  allocate(a, source=acsr)

  call move_alloc(from=acsr%irp, to=a%irp)

  test_passed = .true.
  do i = 1, size(a%irp)
    if (a%irp(i) /= expected_values(i)) then
      test_passed = .false.
      exit
    end if
  end do

  if (test_passed) then
    print *, "Test Passed: Array contents are as expected."
  else
    print *, "Test Failed: Array contents differ from expected."
    stop 1
  end if

end program test_bug23