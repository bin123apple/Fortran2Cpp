program test_upper
  implicit none
  character(len = 20) :: result

  result = Upper("abcdefgh")
  if (trim(result) /= "ab") then
    print *, "Test failed: Expected 'ab', got '", trim(result), "'"
    stop 1
  else
    print *, "Test passed."
  end if

contains

  Character(len = 20) Function Upper(string)
    Character(len = *) string
    integer :: i

    i = size(transfer(string, "xy", len(string)))
    if (i /= len(string)) stop 2
    Upper = ""
    Upper(1:2) = transfer(merge(transfer(string, "xy", len(string)), string(1:2), .true.), "xy")
    return
  end function Upper

end program test_upper