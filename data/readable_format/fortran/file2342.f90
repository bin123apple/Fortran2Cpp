PROGRAM TestCirfil
    IMPLICIT NONE
    INTEGER, PARAMETER :: IXEXT = 10, IYEXT = 10
    REAL :: ARRAY(IXEXT, IYEXT)
    REAL :: XCEN, YCEN, RAD, RVAL
    INTEGER :: I, J

    ! Initialize the array with zeros
    ARRAY = 0.0
    XCEN = 5.0
    YCEN = 5.0
    RAD = 3.0
    RVAL = 1.0

    ! Call the CIRFIL subroutine
    CALL CIRFIL(XCEN, YCEN, RAD, RVAL, IXEXT, IYEXT, ARRAY)

    ! Print the array to verify the result
    DO J = 1, IYEXT
        DO I = 1, IXEXT
            WRITE(*,'(F5.1)',ADVANCE='NO') ARRAY(I,J)
        END DO
        WRITE(*,*)
    END DO
END PROGRAM TestCirfil

SUBROUTINE CIRFIL(XCEN, YCEN, RAD, RVAL, IXEXT, IYEXT, ARRAY)
    INTEGER :: IXEXT, IYEXT, IXCEN, IYCEN, IRAD
    REAL :: ARRAY(IXEXT, IYEXT)
    REAL :: XCEN, YCEN, RAD, RVAL, KR
    INTEGER :: I, J, JMIN, JMAX, IMIN, IMAX

    IXCEN = NINT(XCEN + 1)
    IYCEN = NINT(YCEN + 1)
    IRAD = NINT(RAD)
    JMIN = MAX(1, IYCEN - IRAD)
    JMAX = MIN(IYEXT, IYCEN + IRAD)
    IMIN = MAX(1, IXCEN - IRAD)
    IMAX = MIN(IXEXT, IXCEN + IRAD)

    DO J = JMIN, JMAX
        DO I = IMIN, IMAX
            KR = SQRT(REAL((I - IXCEN)**2 + (J - IYCEN)**2))
            IF (KR <= RAD) THEN
                ARRAY(I, J) = RVAL
            END IF
        END DO
    END DO
END SUBROUTINE CIRFIL