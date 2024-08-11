module proglen_mod
  implicit none
contains
  subroutine testStringLength(s, expected_length)
    class(*), intent(in) :: s
    integer, intent(in) :: expected_length
    integer :: l2

    select type(s)
    type is (character(len=*))
      l2 = len(s)
    end select

    if (l2 == expected_length) then
      print *, "Test Passed. String length is: ", l2
    else
      print *, "Test Failed. Expected: ", expected_length, " Got: ", l2
    end if
  end subroutine testStringLength
end module proglen_mod

program proglen
  use proglen_mod
  implicit none

  class(*), allocatable :: s
  allocate(s, source = '123  ')
  call testStringLength(s, 5)
end program proglen