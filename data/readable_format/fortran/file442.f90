module ecosystems_module
  implicit none
  type :: Deriv
    character(len=10) :: name
  end type Deriv

  character(len=8), dimension(2), parameter :: &
       DEF_ECOSYSTEMS = (/ "Gridxxxx", "StringYY" /)

  type(Deriv), save :: DepEcoSystem = Deriv(DEF_ECOSYSTEMS(1))

contains
  subroutine Init_EcoSystems()
    integer :: i = 2
    DepEcoSystem = Deriv(DEF_ECOSYSTEMS(i))
  end subroutine Init_EcoSystems
  
  subroutine check_system(expected_name, test_id)
    character(len=*), intent(in) :: expected_name
    integer, intent(in) :: test_id
    if (DepEcoSystem%name == expected_name) then
      print *, "Test", test_id, "passed."
    else
      print *, "Test", test_id, "failed: expected", expected_name, "but got", DepEcoSystem%name
    end if
  end subroutine check_system
end module ecosystems_module

program test_ecosystems
  use ecosystems_module
  implicit none
  
  ! Test 1: Check initial condition
  call check_system("Gridxxxx", 1)
  
  DepEcoSystem%name = 'ABCDEFGHIJ'
  call Init_EcoSystems()
  
  ! Test 2: After Init_EcoSystems
  call check_system("StringYY", 2)
end program test_ecosystems