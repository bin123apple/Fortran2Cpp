module example_module
  implicit none

  type :: foo
    integer :: num
  end type foo

  type, extends(foo) :: foo_1
    real, dimension(:), allocatable :: arr
  end type foo_1

  contains

  subroutine set_num(f, new_num)
    class(foo), intent(inout) :: f
    integer, intent(in) :: new_num
    f%num = new_num
  end subroutine set_num

  function create_foo(val) result(f)
    integer, intent(in) :: val
    type(foo) :: f
    f%num = val
  end function create_foo

end module example_module

program test_example
  use example_module
  implicit none
  type(foo) :: myFoo
  type(foo_1) :: myFoo1
  real :: testArray(3) = [1.0, 2.0, 3.0]

  ! Testing the create_foo function
  myFoo = create_foo(10)
  print *, "Created foo with num=", myFoo%num

  ! Testing the set_num subroutine
  call set_num(myFoo, 20)
  print *, "After set_num, foo num=", myFoo%num

  ! Testing the foo_1 type with array allocation and setting num
  myFoo1%arr = [3.0, 2.0, 1.0]
  call set_num(myFoo1, 30)
  print *, "For foo_1, num=", myFoo1%num, " and arr=", myFoo1%arr

end program test_example