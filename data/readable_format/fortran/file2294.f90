! single_finalize.f90
program test_finalize
  implicit none

  ! Mock implementations of the dependencies
  call finalize()

  print *, "Finalize subroutine executed successfully."

contains

  subroutine finalize_dyn()
    print *, "finalize_dyn called"
  end subroutine finalize_dyn

  subroutine finalize_phy()
    print *, "finalize_phy called"
  end subroutine finalize_phy

  subroutine shtns_destroy()
    print *, "shtns_destroy called"
  end subroutine shtns_destroy

  subroutine finalize()
    ! Call the dependencies within the finalize subroutine
    call finalize_dyn()
    call finalize_phy()
    call shtns_destroy()
  end subroutine finalize

end program test_finalize