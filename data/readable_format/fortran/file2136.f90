PROGRAM TestREDUC
    INTEGER, PARAMETER :: NM = 4, N = 3
    INTEGER :: IERR
    REAL, DIMENSION(NM,NM) :: A, B
    REAL, DIMENSION(NM) :: DL
    INTEGER :: I, J

    ! Initialize matrices A and B
    A = RESHAPE(SOURCE = [1.0, 0.5, 0.2, 0.0, &
                          0.5, 1.0, 0.3, 0.0, &
                          0.2, 0.3, 1.0, 0.0, &
                          0.0, 0.0, 0.0, 0.0], SHAPE = [NM, NM])
    
    B = RESHAPE(SOURCE = [1.0, 0.5, 0.2, 0.0, &
                          0.5, 1.0, 0.3, 0.0, &
                          0.2, 0.3, 1.0, 0.0, &
                          0.0, 0.0, 0.0, 0.0], SHAPE = [NM, NM])
    
    CALL REDUC(NM, N, A, B, DL, IERR)

    PRINT *, 'IERR = ', IERR
    PRINT *, 'A = '
    DO I = 1, NM
        WRITE(*, '(4F6.2)') (A(I,J), J=1,NM)
    END DO

    PRINT *, 'B = '
    DO I = 1, NM
        WRITE(*, '(4F6.2)') (B(I,J), J=1,NM)
    END DO

    PRINT *, 'DL = ', DL

    CONTAINS

    SUBROUTINE REDUC(NM, N, A, B, DL, IERR)
        INTEGER I,J,K,N,I1,J1,NM,NN,IERR
        REAL A(NM,*),B(NM,*),DL(*)
        REAL X,Y
        IERR = 0
        NN = ABS(N)
        IF (N .LT. 0) GO TO 100
        DO 80 I = 1, N
            I1 = I - 1
            DO 80 J = I, N
                X = B(I,J)
                IF (I .EQ. 1) GO TO 40
                DO 20 K = 1, I1
    20              X = X - B(I,K) * B(J,K)
    40              IF (J .NE. I) GO TO 60
                    IF (X .LE. 0.0E0) GO TO 1000
                    Y = SQRT(X)
                    DL(I) = Y
                    GO TO 80
    60              B(J,I) = X / Y
    80          CONTINUE
    100     DO 200 I = 1, NN
                I1 = I - 1
                Y = DL(I)
                DO 200 J = I, NN
                    X = A(I,J)
                    IF (I .EQ. 1) GO TO 180
                    DO 160 K = 1, I1
    160                X = X - B(I,K) * A(J,K)
    180                A(J,I) = X / Y
    200         CONTINUE
            DO 300 J = 1, NN
                J1 = J - 1
                DO 300 I = J, NN
                    X = A(I,J)
                    IF (I .EQ. J) GO TO 240
                    I1 = I - 1
                    DO 220 K = J, I1
    220                X = X - A(K,J) * B(I,K)
    240                IF (J .EQ. 1) GO TO 280
                    DO 260 K = 1, J1
    260                X = X - A(J,K) * B(I,K)
    280                A(I,J) = X / DL(I)
    300         CONTINUE
            GO TO 1001
    1000    IERR = 7 * N + 1
    1001    RETURN
    END SUBROUTINE REDUC
END PROGRAM TestREDUC