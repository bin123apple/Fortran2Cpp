program test_irjc_matrix
  implicit none

  ! Type definitions directly included
  type irjc_square_matrix
    integer :: neqns
    integer :: nttbr
    integer :: ndeg
    integer, allocatable :: irow(:), jcol(:)
    real, allocatable :: val(:,:)
  end type irjc_square_matrix

  type irjc_mn_matrix
    integer :: nrows
    integer :: ncols
    integer :: nttbr
    integer :: ndeg
    integer, allocatable :: irow(:), jcol(:)
    real, allocatable :: val(:,:)
  end type irjc_mn_matrix

  ! Example variables
  type(irjc_square_matrix) :: square_matrix
  integer :: i

  ! Initialize data for the square matrix
  square_matrix%neqns = 3
  square_matrix%nttbr = 2
  square_matrix%ndeg = 1
  allocate(square_matrix%irow(3), square_matrix%jcol(3))
  allocate(square_matrix%val(3,3))

  square_matrix%irow = [1, 2, 3]
  square_matrix%jcol = [1, 2, 3]
  do i = 1, square_matrix%neqns
    square_matrix%val(i,:) = real(i, kind=4)
  end do

  ! Demonstrating usage
  print *, "Square Matrix"
  print *, "neqns: ", square_matrix%neqns
  print *, "irow: ", square_matrix%irow
  print *, "jcol: ", square_matrix%jcol
  print *, "val: "
  do i = 1, square_matrix%neqns
    print *, square_matrix%val(i,:)
  end do

end program test_irjc_matrix