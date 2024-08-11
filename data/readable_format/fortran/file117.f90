module string_manipulation
  implicit none
contains
  subroutine convert_case (string, direction)
    character(len=*), intent(inout) :: string
    integer, intent(in) :: direction
    integer :: i, upper_to_lower, len_string
    
    upper_to_lower = iachar("a") - iachar("A")
    len_string = len_trim(string)
    
    do i = 1, len_string
       select case (string(i:i))
       case ('A':'Z')
          if (direction == 0) string(i:i) = achar(iachar(string(i:i)) + upper_to_lower)
       case ('a':'z')
          if (direction == 1) string(i:i) = achar(iachar(string(i:i)) - upper_to_lower)
       end select
    end do
  end subroutine convert_case
end module string_manipulation

program test_string_manipulation
  use string_manipulation
  implicit none

  character(len=20) :: test_string

  ! Test 1: Convert "Hello, World!" to lowercase
  test_string = "Hello, World!"
  call convert_case(test_string, 0)
  if (test_string == "hello, world!") then
      print *, "Test 1 Passed"
  else
      print *, "Test 1 Failed"
  end if

  ! Test 2: Convert "Hello, World!" to uppercase
  test_string = "Hello, World!"
  call convert_case(test_string, 1)
  if (test_string == "HELLO, WORLD!") then
      print *, "Test 2 Passed"
  else
      print *, "Test 2 Failed"
  end if
end program test_string_manipulation