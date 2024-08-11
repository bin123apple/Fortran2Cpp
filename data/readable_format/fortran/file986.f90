module test_utils
  implicit none
contains
  subroutine assert(condition, message)
    logical, intent(in) :: condition
    character(len=*), intent(in) :: message
    if (.not. condition) then
      print *, "Assertion failed:", trim(message)
      call abort
    end if
  end subroutine assert
end module test_utils

program test
  use test_utils
  implicit none
  type t
     character(len=2) :: x
  end type t
  type(t) :: a
  character(len=3) :: b
  character(len=10) :: line

  a%x = 'a'
  write(unit=line, fmt='(A,A)') trim(a%x), "X"
  call assert(line == 'aX        ', "Test 1 Failed")

  b = 'ab'
  write(unit=line, fmt='(A,A)') trim(b), "Y"
  call assert(line == 'abY       ', "Test 2 Failed")

  print *, "All tests passed."
end program test