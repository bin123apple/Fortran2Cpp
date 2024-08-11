module ldaU_hp
  implicit none
contains
  ! Function to sum elements of an array
  function sum_array(arr) result(total)
    real, intent(in) :: arr(:)
    real :: total
    total = sum(arr)
  end function sum_array
end module ldaU_hp

program test_ldaU_hp
  use ldaU_hp
  implicit none
  real :: test_array(5), result

  ! Define a test array
  test_array = [1.0, 2.0, 3.0, 4.0, 5.0]
  ! Use the sum_array function from the ldaU_hp module
  result = sum_array(test_array)

  ! Output the result to verify correctness
  print *, "Sum of array elements: ", result
  if (result == 15.0) then
    print *, "Test passed: sum_array works correctly."
  else
    print *, "Test failed: sum_array does not work correctly."
  end if
end program test_ldaU_hp