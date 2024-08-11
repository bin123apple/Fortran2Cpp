program test_matrix_initialization
  implicit none
  integer :: n
  real(8), allocatable :: a(:,:), b(:,:), c(:,:)

  ! Specify the size of the matrices
  n = 3

  ! Allocate the matrices
  allocate(a(n,n), b(n,n), c(n,n))

  ! Initialize matrices a and b if needed (here we just allocate them)
  call random_initialize(a, n)
  call random_initialize(b, n)

  ! Call the subroutine to initialize matrix c to zero
  call matrix_initialize_to_zero(c, n)

  ! Check if matrix c is correctly initialized to zero
  if (check_matrix_zero(c, n)) then
    print *, "Test Passed: Matrix c is correctly initialized to zero."
  else
    print *, "Test Failed: Matrix c is not correctly initialized."
  end if

  ! Deallocate the matrices
  deallocate(a, b, c)

contains

  subroutine matrix_initialize_to_zero(c, n)
    integer, intent(in) :: n
    real(8), dimension(n,n), intent(out) :: c
    c = 0.d0
  end subroutine matrix_initialize_to_zero

  subroutine random_initialize(matrix, n)
    integer, intent(in) :: n
    real(8), dimension(n,n), intent(out) :: matrix
    integer :: i, j
    do i = 1, n
      do j = 1, n
        matrix(i, j) = rand()  ! Just an example, Fortran's random number generator should be used
      end do
    end do
  end subroutine random_initialize

  function check_matrix_zero(matrix, n) result(is_zero)
    integer, intent(in) :: n
    real(8), dimension(n,n), intent(in) :: matrix
    logical :: is_zero
    integer :: i, j
    is_zero = .true.
    do i = 1, n
      do j = 1, n
        if (matrix(i, j) /= 0.d0) then
          is_zero = .false.
          return
        end if
      end do
    end do
  end function check_matrix_zero

end program test_matrix_initialization