program main
  implicit none
  real, dimension(3,2) :: a
  real, dimension(2,3) :: b
  real, dimension(:,:), allocatable :: ret
  integer :: i, j

  ! Initialize matrices
  a = reshape([1.0, 1.0, 1.0, 1.0, 1.0, 1.0], [3, 2])
  b = reshape([2.3, 2.3, 2.3, 2.3, 2.3, 2.3], [2, 3])

  ! Perform matrix multiplication
  call matrix_multiply(a, b, ret)

  ! Print results for verification (simple test)
  print *, "Result matrix:"
  do i = 1, size(ret, 1)
    print *, (ret(i, j), j = 1, size(ret, 2))
  end do

  ! Cleanup
  deallocate(ret)

contains

  subroutine matrix_multiply(a, b, ret)
    real, intent(in) :: a(:,:), b(:,:)
    real, intent(out), allocatable :: ret(:,:)
    allocate(ret(size(a,1),size(b,2)))
    ret = matmul(a, b)
  end subroutine matrix_multiply

end program main