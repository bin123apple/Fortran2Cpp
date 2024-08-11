! test_ppm_hamjac_ext.f90
program test_ppm_hamjac_ext
    implicit none

    call test_single_precision()
    call test_double_precision()

contains

    subroutine test_single_precision()
        print *, "This is the single precision routine in Fortran."
    end subroutine test_single_precision

    subroutine test_double_precision()
        print *, "This is the double precision routine in Fortran."
    end subroutine test_double_precision

end program test_ppm_hamjac_ext