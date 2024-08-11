module test1
  use, intrinsic :: iso_c_binding
  implicit none
contains
  subroutine sub1(argv) bind(c,name="sub1")
    type(c_ptr), intent(in) :: argv
    ! This subroutine intentionally left empty to match your example
  end subroutine sub1

  subroutine sub2
    type(c_ptr), dimension(1), target :: argv = c_null_ptr
    character(c_char), dimension(1), target :: s = c_null_char
    call sub1(c_loc(argv))
    ! This subroutine intentionally left empty to match your example
  end subroutine sub2
end module test1

program test2
  use iso_c_binding
  use test1
  implicit none
  type(c_ptr), target, save :: argv

  call sub1(c_loc(argv))
  print *, "sub1 called from test2 successfully."

  call sub2
  print *, "sub2 called from test2 successfully."
end program test2