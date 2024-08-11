! Define a module that includes the add_arrays subroutine
module array_operations
  implicit none
contains
  ! Subroutine for adding two arrays
  subroutine add_arrays(array1, array2, sum_array, size)
    real, dimension(size), intent(in) :: array1, array2
    real, dimension(size), intent(out) :: sum_array
    integer, intent(in) :: size
    integer :: i

    do i = 1, size
       sum_array(i) = array1(i) + array2(i)
    end do
  end subroutine add_arrays
end module array_operations

! Main program for testing
program test_add_arrays
  use array_operations  ! Use the module here
  implicit none
  real, dimension(5) :: test_array1 = [1.0, 2.0, 3.0, 4.0, 5.0]
  real, dimension(5) :: test_array2 = [5.0, 4.0, 3.0, 2.0, 1.0]
  real, dimension(5) :: expected_sum = [6.0, 6.0, 6.0, 6.0, 6.0]
  real, dimension(5) :: result_sum
  integer :: i
  logical :: test_passed = .true.

  ! Call the subroutine from the module
  call add_arrays(test_array1, test_array2, result_sum, 5)

  ! Check if the result matches the expected sum
  do i = 1, 5
     if (result_sum(i) /= expected_sum(i)) then
        test_passed = .false.
        exit
     endif
  end do

  ! Output the test result
  if (test_passed) then
     print *, "Test Passed"
  else
     print *, "Test Failed"
  endif
end program test_add_arrays