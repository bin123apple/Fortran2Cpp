program mphys_test
  implicit none

  ! Dummy scheme identifiers
  integer, parameter :: improcess_thompson09 = 1
  integer, parameter :: improcess_thompson07 = 2
  integer, parameter :: improcess_morr_two_moment = 3
  integer, parameter :: improcess_um7_3 = 4
  integer, parameter :: improcess_tau_bin = 5
  integer, parameter :: improcess_4A = 6
  
  ! Test a scheme
  call mphys_column(improcess_thompson09)
  call mphys_column(improcess_thompson07)
  call mphys_column(improcess_morr_two_moment)
  ! Add calls for other schemes as needed

contains

  subroutine mphys_column(scheme_id)
    integer, intent(in) :: scheme_id

    select case (scheme_id)
    case (improcess_thompson09)
       call mphys_thompson09_interface
    case (improcess_thompson07)
       call mphys_thompson07_interface
    case (improcess_morr_two_moment)
       call mphys_morrison_interface
    case (improcess_um7_3)
       call mphys_um7_3_interface
    case (improcess_tau_bin)
       call mphys_tau_bin_interface
    case (improcess_4A)
       call mphys_4A_interface
    end select
  end subroutine mphys_column
  
  ! Dummy interfaces for illustration
  subroutine mphys_thompson09_interface
    print *, "Thompson 09 interface called"
  end subroutine

  subroutine mphys_thompson07_interface
    print *, "Thompson 07 interface called"
  end subroutine
  
  subroutine mphys_morrison_interface
    print *, "Morrison interface called"
  end subroutine

  subroutine mphys_um7_3_interface
    print *, "UM7_3 interface called"
  end subroutine

  subroutine mphys_tau_bin_interface
    print *, "TAU BIN interface called"
  end subroutine

  subroutine mphys_4A_interface
    print *, "4A interface called"
  end subroutine

end program mphys_test