PROGRAM testZLASWP
  IMPLICIT NONE
  INTEGER, PARAMETER :: N = 4, LDA = 4, K1 = 1, K2 = 4
  INTEGER :: INCX, I, J
  COMPLEX*16, ALLOCATABLE :: A(:,:)
  INTEGER :: IPIV(4)
  INCX = 1

  ALLOCATE(A(LDA,N))
  ! Initialize A with some values
  DO I = 1, N
    DO J = 1, N
      A(I, J) = COMPLEX(I, J)
    END DO
  END DO
  ! Define pivot indices for testing
  IPIV = (/ 4, 3, 2, 1 /)

  CALL ZLASWP(N, A, LDA, K1, K2, IPIV, INCX)

  ! Print the resulting matrix
  PRINT *, "Resulting Matrix A:"
  DO I = 1, N
    PRINT *, (A(I, J), J = 1, N)
  END DO

  CONTAINS

    SUBROUTINE ZLASWP( N, A, LDA, K1, K2, IPIV, INCX )
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
         IX0 = K1 + ( K1-K2 )*INCX
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

    END SUBROUTINE ZLASWP

END PROGRAM testZLASWP