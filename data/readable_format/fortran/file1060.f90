module types_and_subs
  implicit none

  ! Global variable
  integer :: sum = 0

  type :: t
    integer :: i
    procedure(), pointer, nopass :: ppc => null()
    procedure(), pointer, nopass :: proc => null()
  end type t

  type, extends(t) :: t2
    procedure(), pointer, nopass :: proc2 => null()
  end type t2

contains
  subroutine sub(y)
    integer, intent(in) :: y
    sum = sum + y
  end subroutine sub

  ! Note: Adjusted to not use polymorphism for simplicity in this example
  subroutine sub2()
    sum = sum + 1
  end subroutine sub2

end module types_and_subs

program test_program
  use types_and_subs
  implicit none

  type(t) :: x
  type(t2) :: x2

  ! Unit testing code
  call test()

contains

  subroutine test()
    type(t) :: test_x
    type(t2) :: test_x2

    ! Reset global sum for testing
    sum = 0

    ! Test setting and calling procedure pointers
    test_x%i = 10
    test_x%ppc => sub
    call test_x%ppc(5)
    if (sum /= 5) then
        write(*,*) 'Test failed: sum after sub(5)'
        stop
    end if

    ! Test type extension and additional procedure pointer
    test_x2%proc2 => sub
    call test_x2%proc2(5)
    if (sum /= 10) then
        write(*,*) 'Test failed: sum after test_x2%proc2(5)'
        stop
    end if

    ! Simplified test for proc without polymorphism
    test_x%proc => sub2
    call test_x%proc()
    if (sum /= 11) then
        write(*,*) 'Test failed: sum after sub2()'
        stop
    end if

    write(*,*) 'All Fortran tests passed.'

  end subroutine test

end program test_program