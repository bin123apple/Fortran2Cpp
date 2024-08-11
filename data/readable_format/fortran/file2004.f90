module m
  implicit none
contains
  subroutine sub(a)
    interface
      function a(x)
        real :: a
        real, intent(in) :: x
      end function a
    end interface
    print *, a(4.0)
  end subroutine sub
end module m

! Declare the function 'foo' outside the program unit to ensure it's globally accessible
real function foo(x)
  real, intent(in) :: x
  foo = x * 2.0
end function foo

program testProgram
  use m
  implicit none
  
  ! Prototype declaration for 'foo' to satisfy the implicit none
  interface
    function foo(x)
      real :: foo
      real, intent(in) :: x
    end function foo
  end interface

  ! The test subroutine declaration
  call testFoo()
  ! Using the subroutine 'sub' from module 'm' and passing 'foo' function to it
  call sub(foo)

contains

  subroutine testFoo()
    real :: expected, result

    expected = 8.0
    ! Directly call foo within testFoo to check its functionality
    result = foo(4.0)

    if (result == expected) then
      print *, "Test passed."
    else
      print *, "Test failed."
    endif
  end subroutine testFoo

end program testProgram