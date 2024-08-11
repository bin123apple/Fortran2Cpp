program test_char2type
  implicit none

  integer :: result
  
  ! Test with 'E'
  result = char2type('E')
  if (result == 1) then
    print *, "Test with 'E' passed."
  else
    print *, "Test with 'E' failed."
  end if
  
  ! Test with 'e'
  result = char2type('e')
  if (result == 1) then
    print *, "Test with 'e' passed."
  else
    print *, "Test with 'e' failed."
  end if
  
  ! Test with an unrelated character
  result = char2type('x')
  if (result == -1234) then
    print *, "Test with 'x' passed."
  else
    print *, "Test with 'x' failed."
  end if

contains

  function char2type(char)
    character, intent(in) :: char
    integer :: char2type

    select case (char)
      case ('E', 'e')
        char2type = 1
      case default
        char2type = -1234
    end select
  end function char2type

end program test_char2type