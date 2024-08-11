MODULE CLASWP_MOD
  IMPLICIT NONE
CONTAINS
  SUBROUTINE CLASWP(N, A, LDA, K1, K2, IPIV, INCX)
    INTEGER, INTENT(IN) :: N, LDA, K1, K2, INCX
    INTEGER, INTENT(IN) :: IPIV(*)
    COMPLEX, INTENT(INOUT) :: A(LDA, *)
    INTEGER :: I, J, IP, K
    COMPLEX :: TEMP

    DO J = 1, N
      DO I = K1, K2
        IP = IPIV(I)
        IF (IP /= I) THEN
          DO K = 1, LDA
            TEMP = A(K, I)
            A(K, I) = A(K, IP)
            A(K, IP) = TEMP
          END DO
        END IF
      END DO
    END DO

  END SUBROUTINE CLASWP
END MODULE CLASWP_MOD

PROGRAM test_claswp
  USE CLASWP_MOD
  IMPLICIT NONE
  COMPLEX, ALLOCATABLE :: A(:,:)
  INTEGER, ALLOCATABLE :: IPIV(:)
  INTEGER :: N, LDA, K1, K2, INCX, I, J

  ! Test parameters
  N = 5
  LDA = 5
  K1 = 1
  K2 = 5
  INCX = 1

  ! Initialize matrix A and IPIV
  ALLOCATE(A(LDA,N), IPIV(K2))
  DO I = 1, LDA
    DO J = 1, N
      A(I,J) = COMPLEX(I, J)
    END DO
  END DO
  DO I = K1, K2
    IPIV(I) = K2 - I + 1
  END DO

  ! Print original matrix
  PRINT *, 'Before CLASWP:'
  DO I = 1, LDA
    PRINT '(*(F4.0, ", ", F4.0, " "))', A(:, I)
  END DO

  ! Perform the row swap
  CALL CLASWP(N, A, LDA, K1, K2, IPIV, INCX)

  ! Print modified matrix
  PRINT *, 'After CLASWP:'
  DO I = 1, LDA
    PRINT '(*(F4.0, ", ", F4.0, " "))', A(:, I)
  END DO
END PROGRAM test_claswp