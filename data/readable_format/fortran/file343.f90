PROGRAM test_zlaswpf
  IMPLICIT NONE
  INTEGER, PARAMETER :: n = 4
  INTEGER :: ipiv(4) = (/ 2, 3, 4, 1 /)
  COMPLEX*16 :: A(4,4)
  INTEGER :: i, j

  ! Initialize the matrix A
  DO i = 1, n
     DO j = 1, n
        A(i,j) = COMPLEX(i, j)
     END DO
  END DO

  ! Call the subroutine
  CALL ZLASWPF(n, A, 4, 1, 4, ipiv, 1)

  ! Print the result
  PRINT *, 'Resulting Matrix A:'
  DO i = 1, n
     PRINT '(4(F6.1,A,F6.1,A,3X))', (REAL(A(i,j)), ' + i', AIMAG(A(i,j)), ',', j=1,n)
  END DO

END PROGRAM test_zlaswpf

SUBROUTINE ZLASWPF( N, A, LDA, K1, K2, IPIV, INCX )
  INTEGER            INCX, K1, K2, LDA, N
  INTEGER            IPIV( * )
  COMPLEX*16         A( LDA, * )
  INTEGER            I, I1, I2, INC, IP, IX, IX0, J, K, N32
  COMPLEX*16         TEMP

  IF( INCX.GT.0 ) THEN
     IX0 = K1
     I1 = K1
     I2 = K2
     INC = 1
  ELSE IF( INCX.LT.0 ) THEN
     IX0 = 1 + ( 1-K2 )*INCX
     I1 = K2
     I2 = K1
     INC = -1
  ELSE
     RETURN
  END IF

  N32 = ( N / 32 )*32
  IF( N32.NE.0 ) THEN
     DO 30 J = 1, N32, 32
        IX = IX0
        DO 20 I = I1, I2, INC
           IP = IPIV( IX )
           IF( IP.NE.I ) THEN
              DO 10 K = J, J + 31
                 TEMP = A( I, K )
                 A( I, K ) = A( IP, K )
                 A( IP, K ) = TEMP
10             CONTINUE
           END IF
           IX = IX + INCX
20       CONTINUE
30    CONTINUE
  END IF
  IF( N32.NE.N ) THEN
     N32 = N32 + 1
     IX = IX0
     DO 50 I = I1, I2, INC
        IP = IPIV( IX )
        IF( IP.NE.I ) THEN
           DO 40 K = N32, N
              TEMP = A( I, K )
              A( I, K ) = A( IP, K )
              A( IP, K ) = TEMP
40          CONTINUE
        END IF
        IX = IX + INCX
50    CONTINUE
  END IF

  RETURN
END SUBROUTINE ZLASWPF