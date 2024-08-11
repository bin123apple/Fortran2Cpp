program main
  implicit none
  real, dimension(3,2) :: a
  real, dimension(2,3) :: b
  real, dimension(:,:), allocatable :: ret

  ! Initialize matrices
  a = reshape([1.0, 1.0, 1.0, 1.0, 1.0, 1.0], shape(a))
  b = reshape([2.3, 2.3, 2.3, 2.3, 2.3, 2.3], shape(b))

  ! Allocate and compute matrix multiplication
  allocate (ret(3,3))
  ret = matmul(a, b)

  ! Output the result for verification (not in actual tests)
  print *, "Matrix ret:"
  print *, ret

  ! Cleanup
  deallocate(ret)
end program main