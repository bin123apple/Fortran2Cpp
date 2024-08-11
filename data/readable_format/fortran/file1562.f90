PROGRAM TestFPOLY
  IMPLICIT NONE
  INTEGER :: NP, i
  REAL :: X
  REAL, ALLOCATABLE :: P(:)
  
  ! Test case 1
  NP = 5
  X = 2.0
  ALLOCATE(P(NP))
  CALL FPOLY(X, P, NP)
  PRINT *, 'Test Case 1: X = 2.0, NP = 5'
  DO i=1, NP
    PRINT '(A, I1, A, F6.2)', 'P(', i, ') = ', P(i)
  END DO
  DEALLOCATE(P)

  ! Test case 2
  NP = 3
  X = 3.0
  ALLOCATE(P(NP))
  CALL FPOLY(X, P, NP)
  PRINT *, 'Test Case 2: X = 3.0, NP = 3'
  DO i=1, NP
    PRINT '(A, I1, A, F6.2)', 'P(', i, ') = ', P(i)
  END DO
  DEALLOCATE(P)

END PROGRAM TestFPOLY

SUBROUTINE FPOLY(X,P,NP)
  INTEGER :: NP, J
  REAL :: X
  REAL, DIMENSION(NP) :: P
  P(1)=1.0
  DO J=2,NP
    P(J)=P(J-1)*X
  END DO
END SUBROUTINE FPOLY