program nrtype_test
  implicit none

  ! Integer kinds
  integer, parameter :: ikind = selected_int_kind(9)
  integer, parameter :: lkind = selected_int_kind(15)
  
  ! Floating-point kinds
  integer, parameter :: rkind = selected_real_kind(p=6)
  integer, parameter :: dkind = selected_real_kind(p=15)

  ! Constants
  real(kind=rkind), parameter :: pi = 3.1415927_rkind
  real(kind=dkind), parameter :: dpi = 3.14159265358979323846_dkind

  ! Derived types for sparse matrices
  type sparse_single
    integer(ikind) :: rows, cols
    real(rkind), allocatable :: values(:)
    integer(ikind), allocatable :: rowIndex(:), colIndex(:)
  end type sparse_single
  
  type sparse_double
    integer(ikind) :: rows, cols
    real(dkind), allocatable :: values(:)
    integer(ikind), allocatable :: rowIndex(:), colIndex(:)
  end type sparse_double

  ! Example usage of the types and constants
  type(sparse_single) :: example_ss
  type(sparse_double) :: example_sd

  ! Example initialization
  example_ss%rows = 2
  example_ss%cols = 3
  allocate(example_ss%values(example_ss%rows * example_ss%cols))
  allocate(example_ss%rowIndex(example_ss%rows), example_ss%colIndex(example_ss%cols))

  example_sd%rows = 4
  example_sd%cols = 5
  allocate(example_sd%values(example_sd%rows * example_sd%cols))
  allocate(example_sd%rowIndex(example_sd%rows), example_sd%colIndex(example_sd%cols))

  ! Example usage of constants
  print *, "pi (single precision) =", pi
  print *, "dpi (double precision) =", dpi

  ! Clean up
  deallocate(example_ss%values, example_ss%rowIndex, example_ss%colIndex)
  deallocate(example_sd%values, example_sd%rowIndex, example_sd%colIndex)

end program nrtype_test