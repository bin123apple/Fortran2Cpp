module char_conversion_functions
  use iso_c_binding
  implicit none

contains

  function return_char1(i) result(output) bind(c, name='return_char1')
    integer(c_int), intent(in) :: i
    character(c_char) :: output
    output = achar(i)
  end function return_char1

  function return_char2(i) result(output) bind(c, name='return_char2')
    integer(c_int), intent(in) :: i
    character(c_char) :: output
    output = achar(i)
  end function return_char2

  function return_char3(i) result(output) bind(c, name='return_char3')
    integer(c_int), intent(in) :: i
    character(c_char) :: output
    output = achar(i)
  end function return_char3

end module char_conversion_functions

program test_conversion
  use char_conversion_functions
  use iso_c_binding
  implicit none

  integer(c_int) :: test_values(5)
  integer :: i
  character(c_char) :: result

  ! Initialize test values
  test_values = [65, 66, 97, 98, 48] ! ASCII values for 'A', 'B', 'a', 'b', '0'

  ! Test return_char1
  do i=1, size(test_values)
      result = return_char1(test_values(i))
      print *, "return_char1(", test_values(i), ") = ", achar(ichar(result))
  end do

  ! Test return_char2
  do i=1, size(test_values)
      result = return_char2(test_values(i))
      print *, "return_char2(", test_values(i), ") = ", achar(ichar(result))
  end do

  ! Test return_char3
  do i=1, size(test_values)
      result = return_char3(test_values(i))
      print *, "return_char3(", test_values(i), ") = ", achar(ichar(result))
  end do
end program test_conversion