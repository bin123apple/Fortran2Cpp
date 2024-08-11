PROGRAM testDSMTV
    IMPLICIT NONE
    INTEGER, PARAMETER :: N = 3, NELT = 5
    INTEGER :: ISYM
    DOUBLE PRECISION, DIMENSION(N) :: X, Y
    DOUBLE PRECISION, DIMENSION(NELT) :: A
    INTEGER, DIMENSION(NELT) :: IA
    INTEGER, DIMENSION(N+1) :: JA
    INTEGER :: I

    ! Define a 3x3 sparse matrix:
    ! [ 2.0 0.0 3.0 ]
    ! [ 0.0 4.0 0.0 ]
    ! [ 5.0 0.0 6.0 ]
    ! And a vector: [1.0, 2.0, 3.0]

    ! Sparse matrix representation (A, IA, JA)
    A = (/ 2.0, 3.0, 4.0, 5.0, 6.0 /)
    IA = (/ 1, 3, 2, 1, 3 /)
    JA = (/ 1, 3, 4, 6 /) ! Adjusted for the correct dimension

    X = (/ 1.0, 2.0, 3.0 /)
    ISYM = 0  ! Non-symmetric matrix

    CALL DSMTV(N, X, Y, NELT, IA, JA, A, ISYM)

    PRINT *, 'Resulting vector Y:'
    DO I = 1, N
        PRINT *, Y(I)
    END DO
END PROGRAM testDSMTV

SUBROUTINE DSMTV (N, X, Y, NELT, IA, JA, A, ISYM)
    INTEGER ISYM, N, NELT
    DOUBLE PRECISION A(NELT), X(N), Y(N)
    INTEGER IA(NELT), JA(N+1)
    INTEGER I, IBGN, ICOL, IEND, IROW, J, JBGN, JEND

    DO 10 I = 1, N
        Y(I) = 0
10  CONTINUE

    DO 30 IROW = 1, N
        IBGN = JA(IROW)
        IEND = JA(IROW+1)-1

        DO 20 I = IBGN, IEND
            Y(IROW) = Y(IROW) + A(I)*X(IA(I))
20      CONTINUE
30  CONTINUE

    IF( ISYM .EQ. 1 ) THEN

        DO 50 ICOL = 1, N
            JBGN = JA(ICOL) + 1
            JEND = JA(ICOL+1) - 1
            IF( JBGN .GT. JEND ) GOTO 50

            DO 40 J = JBGN, JEND
                Y(IA(J)) = Y(IA(J)) + A(J)*X(ICOL)
40          CONTINUE
50      CONTINUE
    ENDIF
    RETURN
END SUBROUTINE DSMTV