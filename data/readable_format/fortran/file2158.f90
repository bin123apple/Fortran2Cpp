PROGRAM TEST_REGISY
    IMPLICIT REAL*8 (A-H,O-Z)
    LOGICAL IFL
    COMMON/WAIT/ WEIGHT(100), IWEIGHT
    COMMON/CAL/ Y1(100), X1(100), X2(100), Y2(100), IPASS, IMAP

    INTEGER :: M, N, I
    REAL*8 :: XC(8), RC(100)

    ! Initialize test data
    M = 5
    N = 8
    IFL = .TRUE.
    IWEIGHT = 1
    IPASS = 3
    XC = (/1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0/)
    
    DO I = 1, M
        X1(I) = I * 2.0
        Y1(I) = I * 1.0
        Y2(I) = I * 3.0
        WEIGHT(I) = I * 0.5
    END DO

    CALL REGISY(M, N, XC, RC, IFL)

    PRINT *, 'Fortran Results:'
    DO I = 1, M
        PRINT *, 'RC(', I, ') = ', RC(I)
    END DO

END PROGRAM TEST_REGISY

SUBROUTINE REGISY(M, N, XC, RC, IFL)
    IMPLICIT REAL*8 (A-H,O-Z)
    COMMON/WAIT/ WEIGHT(100), IWEIGHT
    COMMON/CAL/ Y1(100), X1(100), X2(100), Y2(100), IPASS, IMAP
    DIMENSION XC(N), RC(M)
    LOGICAL IFL
    INTEGER I
    REAL*8 Y2MY1, XX2, YY2, RCSIMP

    DO I = 1, M
        Y2MY1 = Y2(I) - Y1(I)
        XX2 = X1(I) * X1(I)
        YY2 = Y1(I) * Y1(I)
        RCSIMP = Y2MY1 - (XC(1) + XC(2) * X1(I) + XC(3) * Y1(I))
        RC(I) = RCSIMP
        IF (IPASS .EQ. 1) GO TO 11
        RC(I) = RC(I) - (XC(4) * XX2 + XC(5) * Y1(I) * X1(I) + XC(6) * YY2)
        IF (IPASS .EQ. 2) GO TO 11
        RC(I) = RC(I) - (XC(7) * Y1(I) * (XX2 + YY2) + XC(8) * Y1(I) * ((XX2 + YY2) ** 2))
    11 CONTINUE
        IF (IWEIGHT .EQ. 1) RC(I) = RC(I) * WEIGHT(I)
    END DO

    RETURN
END SUBROUTINE REGISY