module matrix_operations
contains
  subroutine sub(a, b)
    real, dimension(:,:), intent(in) :: a
    real, dimension(:,:), intent(out), allocatable :: b
    b = transpose(a)
  end subroutine sub
end module matrix_operations

program main
  use matrix_operations
  implicit none
  real, dimension(2,2) :: a
  real, dimension(:,:), allocatable :: b
  data a /-2., 3., -5., 7./

  call sub(a, b)
  call test_transpose(b)
  b = matmul(transpose(b), a)
  call test_multiply(b)

contains

  subroutine test_transpose(b)
    real, dimension(:,:), intent(in) :: b
    real, dimension(2,2) :: expected_b
    expected_b = reshape([-2., -5., 3., 7.], shape(expected_b))
    if (all(b == expected_b)) then
      print *, "Fortran Test transpose passed!"
    else
      print *, "Fortran Test transpose failed!"
      stop 1
    end if
  end subroutine test_transpose

  subroutine test_multiply(b)
    real, dimension(:,:), intent(in) :: b
    real, dimension(2,2) :: expected_b2
    expected_b2 = reshape([-11., 15., -25., 34.], shape(expected_b2))
    if (all(b == expected_b2)) then
      print *, "Fortran Test multiply passed!"
    else
      print *, "Fortran Test multiply failed!"
      stop 2
    end if
  end subroutine test_multiply

end program main