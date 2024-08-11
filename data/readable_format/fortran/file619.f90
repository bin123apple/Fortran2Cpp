PROGRAM testZLACGV
  IMPLICIT NONE
  INTEGER, PARAMETER :: N=5
  COMPLEX*16, ALLOCATABLE :: X(:)
  INTEGER :: I, INCX

  ALLOCATE(X(N))

  ! Test case 1: INCX = 1
  INCX = 1
  DO I = 1, N
     X(I) = CMPLX(I, I)  ! Initialize X to (1,1), (2,2), ..., (N,N)
  END DO
  CALL ZLACGV(N, X, INCX)
  PRINT *, "Test case 1: INCX = 1"
  DO I = 1, N
     PRINT *, X(I)
  END DO

  ! Test case 2: INCX = 2
  INCX = 2
  DO I = 1, N
     X(I) = CMPLX(I, I)  ! Re-initialize X
  END DO
  CALL ZLACGV(N, X, INCX)
  PRINT *, "Test case 2: INCX = 2"
  DO I = 1, N
     PRINT *, X(I)
  END DO

  DEALLOCATE(X)
END PROGRAM testZLACGV

SUBROUTINE ZLACGV(N, X, INCX)
  INTEGER, INTENT(IN) :: N, INCX
  COMPLEX*16, INTENT(INOUT) :: X(*)
  INTEGER :: I, IOFF

  IF (INCX.EQ.1) THEN
     DO I = 1, N
        X(I) = CONJG(X(I))
     END DO
  ELSE
     IOFF = 1
     IF (INCX.LT.0) THEN
        IOFF = 1 - (N-1) * INCX
     END IF
     DO I = 1, N
        X(IOFF) = CONJG(X(IOFF))
        IOFF = IOFF + INCX
     END DO
  END IF
END SUBROUTINE ZLACGV