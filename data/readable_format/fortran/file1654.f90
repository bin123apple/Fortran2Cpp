module sort_utils
  implicit none
contains
  pure function is_sorted_asc_real(x) result(sorted)
    logical :: sorted
    real, intent(in) :: x(:)
    integer :: i
  
    do i = 2,size(x,1)
       if (x(i - 1) > x(i)) then
          sorted = .false.
          return
       end if
    end do
    sorted = .true.
  end function is_sorted_asc_real
end module sort_utils

program test_is_sorted_asc_real
  use sort_utils
  implicit none
  real, allocatable :: test_array(:)
  logical :: result

  ! Test empty array
  allocate(test_array(0))
  result = is_sorted_asc_real(test_array)
  print *, "Empty array sorted: ", result  ! Expected: .true.

  ! Test single element array
  allocate(test_array(1))
  test_array = [5.0]
  result = is_sorted_asc_real(test_array)
  print *, "Single element array sorted: ", result  ! Expected: .true.

  ! Test fully sorted array
  test_array = [1.0, 2.0, 3.0, 4.0]
  result = is_sorted_asc_real(test_array)
  print *, "Fully sorted array sorted: ", result  ! Expected: .true.

  ! Test partially sorted array
  test_array = [1.0, 3.0, 2.0, 4.0]
  result = is_sorted_asc_real(test_array)
  print *, "Partially sorted array sorted: ", result  ! Expected: .false.

  ! Test completely unsorted array
  test_array = [4.0, 3.0, 2.0, 1.0]
  result = is_sorted_asc_real(test_array)
  print *, "Completely unsorted array sorted: ", result  ! Expected: .false.

  deallocate(test_array)

end program test_is_sorted_asc_real