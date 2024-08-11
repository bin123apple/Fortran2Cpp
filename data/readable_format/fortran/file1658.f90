module test
  implicit none
contains
  subroutine oacc1(result)
    integer, intent(out) :: result
    integer :: i
    result = 0
    do i = 1, 5
      result = result + i
    end do
  end subroutine oacc1
end module test

program unit_test
  use test
  implicit none
  integer :: result

  call oacc1(result)
  if (result == 15) then
    print *, "Test passed."
  else
    print *, "Test failed."
  end if
end program unit_test