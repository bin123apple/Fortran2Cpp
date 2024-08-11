module types_mod
  implicit none
  type :: Sub
    integer :: i
  end type Sub

  type :: T
    type(Sub) :: sub
  end type T

  type :: TU
    real :: r
  end type TU
end module types_mod

subroutine sub0(u)
  use types_mod
  type(T), intent(inout) :: u
  u%sub%i = 0
end subroutine sub0

subroutine sub1()
  use types_mod
  type(T) :: u
  call sub0(u)
end subroutine sub1

subroutine sub2(u)
  use types_mod
  type(TU), intent(inout) :: u
  u%r = 1.0
end subroutine sub2

program test_fortran_code
  use types_mod
  implicit none
  
  type(T) :: u
  type(TU) :: u2
  
  call sub0(u)
  if (u%sub%i /= 0) then
    print *, 'Test sub0 failed: u%sub%i = ', u%sub%i
  else
    print *, 'Test sub0 passed'
  end if
  
  call sub1() ! This is hard to test directly since it doesn't return anything or modify global state
  
  call sub2(u2)
  if (u2%r /= 1.0) then
    print *, 'Test sub2 failed: u2%r = ', u2%r
  else
    print *, 'Test sub2 passed'
  end if
end program test_fortran_code