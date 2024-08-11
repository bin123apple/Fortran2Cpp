! mytype_application.f90
module mytype_application
  implicit none
  private
  public :: mytype_type, mytype_test

  type :: mytype_type
    integer :: i=0
  end type mytype_type

contains

  subroutine mytype_test(mytype)
    type(mytype_type), intent(inout) :: mytype
    mytype%i = mytype%i + 1  ! Example operation
  end subroutine mytype_test

end module mytype_application

program test
  use mytype_application
  implicit none

  type(mytype_type) :: myTypeInstance
  myTypeInstance%i = 5

  call mytype_test(myTypeInstance)

  if (myTypeInstance%i == 6) then
    print *, "Test Passed"
  else
    print *, "Test Failed"
  endif
end program test