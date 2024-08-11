program main
    call mphys_tau_bin_interface
contains

    subroutine mphys_tau_bin_interface
        implicit none
        write(*,'(8(/, A))') &
            "===========================================================",&
            "This is a dummy stub for the Tel-Aviv University bin ",&
            "microphysics code. This code is not part of the current",&
            "distribution.  To obtain the code, either email ",&
            "ben.shipway@metoffice.gov.uk or visit the downloads",&
            "page at http://www.convection.info/microphysics",&
            "The program will now exit...",&
            "==========================================================="
        stop
    end subroutine mphys_tau_bin_interface

end program main