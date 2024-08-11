module c_ptr_tests_7
  use, intrinsic :: iso_c_binding, only: c_ptr, c_null_ptr

contains
  function func0() bind(c)
    type(c_ptr) :: func0
    func0 = c_null_ptr
  end function func0
end module c_ptr_tests_7

program test_c_ptr_tests_7
  use, intrinsic :: iso_c_binding, only: c_ptr, c_null_ptr, c_associated
  use c_ptr_tests_7, only: func0
  implicit none

  type(c_ptr) :: result

  ! Call the function
  result = func0()

  ! Check if the result is associated with NULL (c_null_ptr)
  if (c_associated(result, c_null_ptr)) then
    print *, "Test passed: func0 returned c_null_ptr"
  else
    print *, "Test failed: func0 did not return c_null_ptr"
  end if
end program test_c_ptr_tests_7