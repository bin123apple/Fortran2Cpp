module private_member
  implicit none
  private
  public :: t, func1

  type :: t
    real, public :: i
    real, private :: k = 2.0
  contains
    procedure, pass :: p1
  end type t

contains
  subroutine p1(this, ret1)
    class(t), intent(in) :: this
    integer, intent(out) :: ret1
    
    ret1 = int(this%i + this%k)
  end subroutine p1

  function func1(para1) result(res)
    integer, intent(in) :: para1
    integer :: res
    
    res = para1 * 2
  end function func1
end module private_member

program test
  use private_member
  implicit none
  
  type(t) :: obj
  integer :: result
  integer :: testFunc1

  ! Test p1
  obj%i = 3.0
  call obj%p1(result)
  print *, "Test p1 with i=3.0 and k=2.0, expected result 5, got ", result

  ! Test func1
  testFunc1 = func1(5)
  print *, "Test func1 with para1=5, expected result 10, got ", testFunc1
end program test