MODULE mod_netcdf

IMPLICIT NONE

CONTAINS

SUBROUTINE ncheck(istat, fname)
    INTEGER, INTENT(IN) :: istat
    CHARACTER(*), INTENT(IN) :: fname

    IF (istat /= 0) THEN
        PRINT *, "Error in file operation: ", TRIM(fname)
        STOP
    END IF
END SUBROUTINE ncheck

END MODULE mod_netcdf

PROGRAM test_netcdf
    USE mod_netcdf
    IMPLICIT NONE

    INTEGER :: istat
    CHARACTER(LEN=100) :: fname

    fname = "example_file.nc"
    istat = -1 ! Simulating a file operation error

    CALL ncheck(istat, fname)
END PROGRAM test_netcdf