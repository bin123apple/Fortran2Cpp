module x
  use iso_c_binding
  implicit none
  private :: bar
  private :: my_private_sub
  private :: my_private_sub_2
  public :: my_public_sub
contains
  subroutine bar() bind(c,name="foo") 
  end subroutine bar

  subroutine my_private_sub() bind(c, name="")
  end subroutine my_private_sub

  subroutine my_private_sub_2() bind(c) 
  end subroutine my_private_sub_2

  subroutine my_public_sub() bind(c, name="my_sub")
  end subroutine my_public_sub
end module x

program test_module_x
  use iso_c_binding
  use x, only: my_public_sub
  implicit none

  call my_public_sub()

  print *, "Test PASSED"
end program test_module_x