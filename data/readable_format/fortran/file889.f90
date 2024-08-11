program test
  implicit none
  character(len=4) :: s = 'abcd'
  logical :: b
  
  b = (len(trim(s)) > 0)
  call assert(b)
  
contains
  
  subroutine assert(condition)
    logical, intent(in) :: condition
    if (condition) then
      print *, "Test passed."
    else
      print *, "Test failed."
    endif
  end subroutine assert
  
end program test