module sorting_utilities
  implicit none
contains
  function is_sorted_dble(vec) result(out)
    double precision, intent(in) :: vec(:)
    integer :: out, i
    out = 0
    do i = 2, size(vec)
       if (vec(i) < vec(i - 1)) then
          out = i
          exit
       end if
    end do
  end function is_sorted_dble
end module sorting_utilities

program test_is_sorted
  use sorting_utilities
  implicit none
  double precision, allocatable :: test_array(:)
  integer :: result

  ! Test empty array
  allocate(test_array(0))
  result = is_sorted_dble(test_array)
  print *, "Empty array test (expected 0): ", result
  deallocate(test_array)

  ! Test single element
  allocate(test_array(1))
  test_array(1) = 1.0d0
  result = is_sorted_dble(test_array)
  print *, "Single element test (expected 0): ", result
  deallocate(test_array)

  ! Test sorted array
  allocate(test_array(5))
  test_array = [1.0d0, 2.0d0, 3.0d0, 4.0d0, 5.0d0]
  result = is_sorted_dble(test_array)
  print *, "Sorted array test (expected 0): ", result
  deallocate(test_array)

  ! Test unsorted array
  allocate(test_array(5))
  test_array = [1.0d0, 3.0d0, 2.0d0, 4.0d0, 5.0d0]
  result = is_sorted_dble(test_array)
  print *, "Unsorted array test (expected 3): ", result
  deallocate(test_array)

end program test_is_sorted