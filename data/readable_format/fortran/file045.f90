program test_program
    use iso_fortran_env, only: std_out=>output_unit
    implicit none
    real :: XYTRAN_TRCOEFFS = 0.0
    real :: XYFIT_TRCOEFFS = 5.0

    call test_assignment(XYTRAN_TRCOEFFS, XYFIT_TRCOEFFS)

    if (XYTRAN_TRCOEFFS == XYFIT_TRCOEFFS) then
        write(std_out, *) "Test passed."
    else
        write(std_out, *) "Test failed."
    end if
contains
    subroutine test_assignment(XYTRAN_TRCOEFFS, XYFIT_TRCOEFFS)
        real, intent(inout) :: XYTRAN_TRCOEFFS
        real, intent(in) :: XYFIT_TRCOEFFS
        
        XYTRAN_TRCOEFFS = XYFIT_TRCOEFFS
    end subroutine test_assignment
end program test_program