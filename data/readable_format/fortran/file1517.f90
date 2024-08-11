module math_operations
  implicit none
contains
  function addTwoNumbers(a, b) result(sum)
    integer, intent(in) :: a, b
    integer :: sum

    sum = a + b
  end function addTwoNumbers
end module math_operations

program test_addTwoNumbers
  use math_operations
  implicit none

  integer :: result

  result = addTwoNumbers(2, 3)
  call assert_equal(5, result, "addTwoNumbers test")

contains
  subroutine assert_equal(expected, actual, message)
    integer, intent(in) :: expected, actual
    character(len=*), intent(in) :: message

    if (expected == actual) then
      print *, "Test passed:", trim(message)
    else
      print *, "Test failed:", trim(message)
      print *, "Expected:", expected, "but got:", actual
    endif
  end subroutine assert_equal

end program test_addTwoNumbers