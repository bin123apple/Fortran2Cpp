program add_with_tests
  implicit none

  ! Test the add function
  call test_add()

contains

  function add(a, b) result(res)
    integer, intent(in) :: a, b
    integer :: res
    res = a + b
  end function add

  subroutine test_add()
    integer :: result
    
    ! Test case 1: adding positive numbers
    result = add(5, 3)
    if (result == 8) then
      print *, "Test case 1 passed: 5 + 3 = 8"
    else
      print *, "Test case 1 failed: 5 + 3 did not equal 8"
    endif

    ! Test case 2: adding negative numbers
    result = add(-1, -2)
    if (result == -3) then
      print *, "Test case 2 passed: -1 + (-2) = -3"
    else
      print *, "Test case 2 failed: -1 + (-2) did not equal -3"
    endif

    ! Add more test cases as needed
  end subroutine test_add

end program add_with_tests