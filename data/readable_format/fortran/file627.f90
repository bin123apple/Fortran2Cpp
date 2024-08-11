MODULE ZGEMV__genmod
  INTERFACE 
    SUBROUTINE ZGEMV(TRANS, M, N, ALPHA, A, LDA, X, INCX, BETA, Y, INCY)
      INTEGER, INTENT(IN) :: LDA, M, N, INCX, INCY
      CHARACTER(LEN=1), INTENT(IN) :: TRANS
      COMPLEX(KIND=8), INTENT(IN) :: ALPHA, BETA
      COMPLEX(KIND=8), INTENT(IN) :: A(LDA,*), X(*)
      COMPLEX(KIND=8), INTENT(INOUT) :: Y(*)
    END SUBROUTINE ZGEMV
  END INTERFACE 
END MODULE ZGEMV__genmod

SUBROUTINE ZGEMV(TRANS, M, N, ALPHA, A, LDA, X, INCX, BETA, Y, INCY)
    USE, INTRINSIC :: ISO_C_BINDING, ONLY: C_DOUBLE_COMPLEX
    INTEGER, INTENT(IN) :: LDA, M, N, INCX, INCY
    CHARACTER(LEN=1), INTENT(IN) :: TRANS
    COMPLEX(KIND=C_DOUBLE_COMPLEX), INTENT(IN) :: ALPHA, BETA
    COMPLEX(KIND=C_DOUBLE_COMPLEX), INTENT(IN) :: A(LDA,*), X(*)
    COMPLEX(KIND=C_DOUBLE_COMPLEX), INTENT(INOUT) :: Y(*)
    INTEGER :: i, j
    COMPLEX(KIND=C_DOUBLE_COMPLEX) :: temp

    IF (TRANS == 'N' .OR. TRANS == 'n') THEN
        DO i = 1, M
            temp = (0.0D0, 0.0D0)
            DO j = 1, N
                temp = temp + A(i, j) * X(j)
            END DO
            Y(i) = ALPHA * temp + BETA * Y(i)
        END DO
    ELSE
        ! Implement transpose case if needed
    END IF
END SUBROUTINE ZGEMV

PROGRAM test_zgemv
    USE ZGEMV__genmod
    IMPLICIT NONE
    INTEGER :: M, N, LDA, INCX, INCY
    COMPLEX(KIND=8) :: ALPHA, BETA
    COMPLEX(KIND=8), ALLOCATABLE :: A(:,:), X(:), Y(:)

    M = 2
    N = 2
    LDA = 2
    INCX = 1
    INCY = 1
    ALPHA = (1.0D0, 0.0D0)
    BETA = (0.0D0, 0.0D0)

    ALLOCATE(A(LDA,N), X(N), Y(M))
    A = RESHAPE((/(1.0D0,0.0D0), (3.0D0,0.0D0), (2.0D0,0.0D0), (4.0D0,0.0D0)/), SHAPE(A))
    X = [(1.0D0,0.0D0), (2.0D0,0.0D0)]
    Y = [(0.0D0,0.0D0), (0.0D0,0.0D0)]

    CALL ZGEMV('N', M, N, ALPHA, A, LDA, X, INCX, BETA, Y, INCY)

    PRINT *, "Y:", Y

    DEALLOCATE(A, X, Y)
END PROGRAM test_zgemv