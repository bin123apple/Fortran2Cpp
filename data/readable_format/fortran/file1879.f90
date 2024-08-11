program start_bse_program
    implicit none
    call start_bse
contains

    subroutine start_bse
        implicit none
        character(len=9) :: code = 'BSE'
        ! Manually comment/uncomment the next line for MPI-related testing
        ! call mp_startup()
        call environment_start(code)
    end subroutine start_bse

    subroutine mp_startup()
        ! Mock implementation of the MPI startup procedure
        print *, "MPI startup procedure called."
    end subroutine mp_startup

    subroutine environment_start(code)
        character(len=*) :: code
        ! Mock implementation of the environment start procedure
        print *, "Environment start procedure called with code:", code
    end subroutine environment_start

end program start_bse_program