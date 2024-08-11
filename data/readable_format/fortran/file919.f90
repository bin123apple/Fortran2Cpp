! CSGETNP.f90
SUBROUTINE CSGETNP(X, Y, Z, LIST, LPTR, LEND, L, NPTS, DF, IER)
    INTEGER :: LIST(*), LPTR(*), LEND(*), L, NPTS(L), IER
    DOUBLE PRECISION :: X(*), Y(*), Z(*), DF
    INTEGER :: I, LM1, LP, LPL, N1, NB, NI, NP
    DOUBLE PRECISION :: DNB, DNP, X1, Y1, Z1

    LM1 = L - 1
    IF (LM1 .LT. 1) THEN
        IER = 1
        RETURN
    END IF
    IER = 0

    N1 = NPTS(1)
    X1 = X(N1)
    Y1 = Y(N1)
    Z1 = Z(N1)
    DNP = 2.0D0
    NP = 0

    DO I = 1, LM1
        NI = NPTS(I)
        DO LP = 1, L
            NB = LIST(LP)
            IF (NB == NI) CYCLE
            DNB = -(X(NB)*X1 + Y(NB)*Y1 + Z(NB)*Z1)
            IF (DNB < DNP) THEN
                NP = NB
                DNP = DNB
            END IF
        END DO
    END DO

    NPTS(L) = NP
    DF = DNP

    RETURN
END SUBROUTINE CSGETNP

PROGRAM TestCSGETNP
    INTEGER, PARAMETER :: N = 5
    DOUBLE PRECISION, DIMENSION(N) :: X = [0.0, 1.0, 2.0, 3.0, 4.0]
    DOUBLE PRECISION, DIMENSION(N) :: Y = [0.0, 1.0, 0.0, 1.0, 0.0]
    DOUBLE PRECISION, DIMENSION(N) :: Z = [0.0, 0.0, 1.0, 1.0, 2.0]
    INTEGER, DIMENSION(N) :: LIST = [1, 2, 3, 4, 5]
    INTEGER, DIMENSION(N) :: LPTR = [1, 2, 3, 4, 5]
    INTEGER, DIMENSION(N) :: LEND = [1, 1, 1, 1, 1]
    INTEGER, DIMENSION(N) :: NPTS = [1, 2, 3, 4, 5]
    INTEGER :: L, IER
    DOUBLE PRECISION :: DF

    L = N
    CALL CSGETNP(X, Y, Z, LIST, LPTR, LEND, L, NPTS, DF, IER)

    IF (IER == 0) THEN
        PRINT *, 'Success: DF = ', DF
        PRINT *, 'NPTS = ', NPTS
    ELSE
        PRINT *, 'An error occurred: IER = ', IER
    END IF
END PROGRAM TestCSGETNP