module m
 implicit none

 type, abstract :: c_abstr
  integer :: i = 0
 end type c_abstr

 type, extends(c_abstr) :: t_a
  class(c_abstr), allocatable :: f
 end type t_a
 
 type, extends(c_abstr) :: t_b
 end type t_b

contains

 subroutine set(y,x)
  class(c_abstr), intent(in)  :: x
  type(t_a),      intent(out) :: y
   allocate( y%f , source=x )
 end subroutine set

end module m

program test
 use m
 implicit none

 type(t_a) :: res
 type(t_b) :: var

  call set(res, var)

  ! Test: res should have i = 0 (default value)
  if (res%i /= 0) then
     print *, "Test failed: res%i should be 0"
  else
     print *, "Test passed: res%i is 0"
  end if

end program test