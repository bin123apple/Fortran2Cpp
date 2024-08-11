module mod
  implicit none
  integer :: i
  integer, dimension(4) :: x
  real, dimension(2,3) :: a
  real, allocatable, dimension(:,:) :: b 
contains
  subroutine foo
    print*, "i=",i
    print*, "x=[",x,"]"
    print*, "a=["
    print*, "[",a(1,1),",",a(1,2),",",a(1,3),"]"
    print*, "[",a(2,1),",",a(2,2),",",a(2,3),"]"
    print*, "]"
    print*, "Setting a(1,2)=a(1,2)+3"
    a(1,2) = a(1,2)+3
  end subroutine foo

  subroutine test_foo
    a(1,2) = 2.0
    call foo
    if (a(1,2) == 5.0) then
      print*, "Test passed."
    else
      print*, "Test failed."
    end if
  end subroutine test_foo
end module mod

program test
  use mod
  call test_foo
end program test