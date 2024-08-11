module mod_test
  implicit none
  type t
    integer :: x
  end type t
contains
  subroutine test_increment()
    type(t) :: x
    integer :: i
    x%x = 0
    do i = 1, 1000
      x%x = x%x + 1
    end do
    if (x%x /= 1000) then
      print *, 'Test failed.'
    else
      print *, 'Test passed.'
    endif
  end subroutine test_increment
end module mod_test

program test
  use mod_test
  call test_increment()
end program test