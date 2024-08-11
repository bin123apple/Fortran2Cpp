PROGRAM TestXYZMOD
    IMPLICIT NONE

    INTEGER, PARAMETER :: NUMNP = 5
    INTEGER, PARAMETER :: NDIM = 3
    REAL :: XOLD(NUMNP), YOLD(NUMNP), ZOLD(NUMNP)
    REAL :: XNEW(NUMNP), YNEW(NUMNP), ZNEW(NUMNP)
    INTEGER :: I

    ! Initialize old coordinates
    DO I = 1, NUMNP
        XOLD(I) = I
        YOLD(I) = I
        ZOLD(I) = I
    END DO

    ! Call the subroutine
    CALL XYZMOD(NUMNP, NDIM, XOLD, YOLD, ZOLD, XNEW, YNEW, ZNEW)

    ! Output the results
    PRINT *, 'XNEW = ', XNEW
    PRINT *, 'YNEW = ', YNEW
    PRINT *, 'ZNEW = ', ZNEW

    ! Check results
    DO I = 1, NUMNP
        IF (XNEW(I) /= XOLD(I)) PRINT *, 'Error in XNEW at index ', I
        IF (YNEW(I) /= YOLD(I)) PRINT *, 'Error in YNEW at index ', I
        IF (NDIM == 3 .AND. ZNEW(I) /= ZOLD(I)) PRINT *, 'Error in ZNEW at index ', I
    END DO

END PROGRAM TestXYZMOD

SUBROUTINE XYZMOD(NUMNP, NDIM, XOLD, YOLD, ZOLD, XNEW, YNEW, ZNEW)
    INTEGER :: NUMNP, NDIM
    REAL :: XOLD(*), YOLD(*), ZOLD(*)
    REAL :: XNEW(*), YNEW(*), ZNEW(*)
    INTEGER :: I

    DO 10 I = 1, NUMNP
        XNEW(I) = XOLD(I)
        YNEW(I) = YOLD(I)
        IF (NDIM == 3) ZNEW(I) = ZOLD(I)
10  CONTINUE
    RETURN
END SUBROUTINE XYZMOD