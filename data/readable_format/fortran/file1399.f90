module force_module
  implicit none
contains
  subroutine force()
    print *, "Force calculation"
  end subroutine force
end module force_module

program test_force
  use force_module
  implicit none

  call force()
end program test_force