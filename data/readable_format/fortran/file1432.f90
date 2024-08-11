module fluid_model_toy
  implicit none

  ! Module variables
  real :: density = 0.0
  real :: velocity = 0.0
  real :: pressure = 0.0

contains
  subroutine initialize()
    ! Initialize variables
    density = 1.0
    velocity = 2.0
    pressure = 101.3
  end subroutine initialize

  subroutine calculate()
    ! Simple calculation (for demonstration)
    pressure = density * velocity * 2.0
  end subroutine calculate

  subroutine deleteModel()
    ! Reset variables
    density = 0.0
    velocity = 0.0
    pressure = 0.0
  end subroutine deleteModel

end module fluid_model_toy

program test_fluid_model
  use fluid_model_toy
  implicit none

  ! Test variables
  logical :: test_passed

  ! Testing initialize
  call initialize()
  if (density == 1.0 .and. velocity == 2.0 .and. pressure == 101.3) then
    print *, 'initialize test passed.'
    test_passed = .true.
  else
    print *, 'initialize test failed.'
    test_passed = .false.
  end if

  ! Testing calculate (assuming initialize has been called)
  call calculate()
  if (pressure == density * velocity * 2.0) then
    print *, 'calculate test passed.'
    test_passed = .true.
  else
    print *, 'calculate test failed.'
    test_passed = .false.
  end if

  ! Testing deleteModel
  call deleteModel()
  if (density == 0.0 .and. velocity == 0.0 .and. pressure == 0.0) then
    print *, 'deleteModel test passed.'
    test_passed = .true.
  else
    print *, 'deleteModel test failed.'
    test_passed = .false.
  end if

  ! Final output
  if (test_passed) then
    print *, 'All tests passed.'
  else
    print *, 'Some tests failed.'
  end if

end program test_fluid_model