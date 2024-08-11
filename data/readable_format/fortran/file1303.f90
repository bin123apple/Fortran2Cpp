program test_f_loc
  use ISO_C_BINDING
  implicit none

  integer, dimension(5), target :: test_array = [1, 2, 3, 4, 5]
  type(C_PTR) :: result_address
  integer(C_INTPTR_T) :: expected_address, result_address_val

  result_address = f_loc(test_array)
  expected_address = transfer(c_loc(test_array(1)), expected_address)
  result_address_val = transfer(result_address, result_address_val)

  if (expected_address == result_address_val) then
    print *, "Test passed: Got the expected address."
  else
    print *, "Test failed: Address does not match."
  end if

contains

  function f_loc(what) result(address)
    use ISO_C_BINDING
    implicit none
    integer, dimension(*), intent(IN), target :: what
    type(C_PTR) :: address
    address = c_loc(what(1))
    return
  end function f_loc

end program test_f_loc