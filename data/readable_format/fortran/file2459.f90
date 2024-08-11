! my_module.f90
module my_module
  use, intrinsic :: iso_c_binding
  implicit none
contains
  subroutine foo() bind(c)
  end subroutine foo

  subroutine foo2() bind(c)
  contains
    integer(c_int) function barbar() bind (c)
      barbar = 1
    end function barbar
  end subroutine foo2

  function one() result(res) bind(c)
    use iso_c_binding
    integer(c_int) :: res
    res = 1
  contains
    integer(c_int) function two() bind (c)
      two = 2
    end function two
  end function one

  function one2() result(res) bind(c)
    use iso_c_binding
    integer(c_int) :: res
    res = 1
  contains
    subroutine three() bind (c)
    end subroutine three
  end function one2
end module my_module

! test_my_module.f90
program test_my_module
  use my_module
  implicit none

  write(*,*) "Testing foo"
  call foo()
  write(*,*) "foo executed successfully."

  write(*,*) "Testing foo2"
  call foo2()
  write(*,*) "foo2 executed successfully."

  write(*,*) "Testing one"
  write(*,*) "one() result:", one()

  write(*,*) "Testing one2"
  write(*,*) "one2() result:", one2()
end program test_my_module