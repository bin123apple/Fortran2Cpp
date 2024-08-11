PROGRAM TestSLARRA
    IMPLICIT NONE
    INTEGER :: N, NSPLIT, INFO
    REAL :: SPLTOL, TNRM
    REAL, DIMENSION(5) :: D
    REAL, DIMENSION(4) :: E, E2
    INTEGER, DIMENSION(5) :: ISPLIT

    N = 5
    D = (/ 1.0, 2.0, 3.0, 4.0, 5.0 /)
    E = (/ 0.1, 0.2, 0.3, 0.4 /)
    E2 = (/ 0.01, 0.04, 0.09, 0.16 /)
    SPLTOL = 0.2
    TNRM = 1.0

    CALL SLARRA(N, D, E, E2, SPLTOL, TNRM, NSPLIT, ISPLIT, INFO)

    PRINT *, 'NSPLIT = ', NSPLIT
    PRINT *, 'ISPLIT = ', ISPLIT(1:NSPLIT)

END PROGRAM TestSLARRA

SUBROUTINE SLARRA(N, D, E, E2, SPLTOL, TNRM, NSPLIT, ISPLIT, INFO)
    IMPLICIT NONE
    INTEGER INFO, N, NSPLIT
    REAL SPLTOL, TNRM
    INTEGER ISPLIT(*)
    REAL D(*), E(*), E2(*)
    REAL ZERO
    PARAMETER (ZERO = 0.0E0)
    INTEGER I
    REAL EABS, TMP1

    INTRINSIC ABS

    INFO = 0
    NSPLIT = 1
    IF (SPLTOL .LT. 0) THEN
        TMP1 = ABS(SPLTOL) * TNRM
        DO 9 I = 1, N - 1
            EABS = ABS(E(I))
            IF (EABS .LE. TMP1) THEN
                E(I) = ZERO
                E2(I) = ZERO
                ISPLIT(NSPLIT) = I
                NSPLIT = NSPLIT + 1
            END IF
 9      CONTINUE
    ELSE
        DO 10 I = 1, N - 1
            EABS = ABS(E(I))
            IF (EABS .LE. SPLTOL * SQRT(ABS(D(I))) * SQRT(ABS(D(I + 1)))) THEN
                E(I) = ZERO
                E2(I) = ZERO
                ISPLIT(NSPLIT) = I
                NSPLIT = NSPLIT + 1
            END IF
 10     CONTINUE
    END IF
    ISPLIT(NSPLIT) = N

    RETURN
END