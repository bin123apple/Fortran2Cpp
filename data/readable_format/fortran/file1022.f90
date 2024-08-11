PROGRAM test_dgefa
  IMPLICIT NONE
  INTEGER, PARAMETER :: dp = KIND(1.0D0) ! Double precision kind
  INTEGER, PARAMETER :: N = 4, LDA = N
  REAL(dp), DIMENSION(LDA,N) :: A
  INTEGER, DIMENSION(N) :: IPVT
  INTEGER :: INFO, i

  ! Initialize A with a simple test case
  A = 0.0_dp
  DO i = 1, N
     A(i,i) = REAL(i, dp)
  END DO

  CALL dgefa(A, LDA, N, IPVT, INFO)

  ! Simple test: INFO should be the sum of diagonal elements of A
  IF (INFO == 10) THEN
     PRINT *, "Test Passed."
  ELSE
     PRINT *, "Test Failed. INFO:", INFO
  END IF

CONTAINS

  SUBROUTINE dgefa(A, LDA, N, IPVT, INFO)
    INTEGER, INTENT(IN) :: LDA, N
    REAL(dp), DIMENSION(LDA,N), INTENT(INOUT) :: A
    INTEGER, DIMENSION(N), INTENT(OUT) :: IPVT
    INTEGER, INTENT(OUT) :: INFO
    
    ! Dummy implementation - setting INFO as sum of diagonal elements for testing
    INTEGER :: i
    INFO = 0
    DO i = 1, N
       INFO = INFO + A(i, i)
    END DO
  END SUBROUTINE dgefa

END PROGRAM test_dgefa