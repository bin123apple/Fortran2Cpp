PROGRAM testDLASWP
  IMPLICIT NONE
  INTEGER, PARAMETER :: n = 4, lda = 4
  INTEGER :: ipiv(4) = (/ 2, 1, 4, 3 /)
  DOUBLE PRECISION :: A(lda, n) = RESHAPE((/ &
       1.0d0, 2.0d0, 3.0d0, 4.0d0, &
       5.0d0, 6.0d0, 7.0d0, 8.0d0, &
       9.0d0, 10.0d0, 11.0d0, 12.0d0, &
       13.0d0, 14.0d0, 15.0d0, 16.0d0 /), (/lda, n/))
  INTEGER :: i, j

  CALL DLASWP(n, A, lda, 1, 4, ipiv, 1)

  PRINT *, 'Resulting Matrix A after DLASWP:'
  DO i = 1, lda
     PRINT '(4F6.2)', A(i, :)
  END DO

END PROGRAM testDLASWP

SUBROUTINE DLASWP(N, A, LDA, K1, K2, IPIV, INCX)
  INTEGER, INTENT(IN) :: N, LDA, K1, K2, INCX
  INTEGER, INTENT(IN) :: IPIV(*)
  DOUBLE PRECISION, INTENT(INOUT) :: A(LDA, *)
  INTEGER :: I, J, IP, K
  DOUBLE PRECISION :: TEMP

  DO J = 1, N
    DO I = K1, K2
      IP = IPIV(I)
      IF (IP .NE. I) THEN
        DO K = 1, LDA
          TEMP = A(K, I)
          A(K, I) = A(K, IP)
          A(K, IP) = TEMP
        END DO
      END IF
    END DO
  END DO
END SUBROUTINE DLASWP