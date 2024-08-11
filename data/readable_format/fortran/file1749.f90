module typesizes
  integer, parameter :: FourByteReal = selected_real_kind(p=6)
  integer, parameter :: EightByteReal = selected_real_kind(p=15)
end module typesizes

module iminloc_functions
  use typesizes, only: FourByteReal, EightByteReal
  implicit none
contains
  function iminloc_int(array) result(idx)
    integer, dimension(:), intent(in) :: array
    integer :: idx
    integer, dimension(1) :: ii
    ii = minloc(array)
    idx = ii(1)
  end function iminloc_int

  function iminloc_float(array) result(idx)
    real(FourByteReal), dimension(:), intent(in) :: array
    integer :: idx
    integer, dimension(1) :: ii
    ii = minloc(array)
    idx = ii(1)
  end function iminloc_float

  function iminloc_double(array) result(idx)
    real(EightByteReal), dimension(:), intent(in) :: array
    integer :: idx
    integer, dimension(1) :: ii
    ii = minloc(array)
    idx = ii(1)
  end function iminloc_double
end module iminloc_functions

program test_iminloc
  use iminloc_functions
  implicit none
  
  integer :: intArray(5) = [5, 3, 2, 4, 1]
  real(FourByteReal) :: floatArray(4) = [3.5, 2.5, 1.5, 4.5]
  real(EightByteReal) :: doubleArray(4) = [2.4, 3.6, 1.2, 4.8]
  
  print *, 'Testing integer array:', intArray
  print *, 'Index of min element:', iminloc_int(intArray)
  
  print *, 'Testing float array:', floatArray
  print *, 'Index of min element:', iminloc_float(floatArray)
  
  print *, 'Testing double array:', doubleArray
  print *, 'Index of min element:', iminloc_double(doubleArray)
end program test_iminloc