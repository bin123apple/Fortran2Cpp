PROGRAM test_sla_gerpvgrw
  IMPLICIT NONE
  REAL, EXTERNAL :: SLA_GERPVGRW
  REAL, DIMENSION(2,2) :: A, AF
  REAL :: result
  INTEGER :: N, NCOLS, LDA, LDAF

  ! Example matrix A and its LU factorization AF
  A = RESHAPE(SOURCE=[1.0, 2.0, 3.0, 4.0], SHAPE=[2,2])
  AF = RESHAPE(SOURCE=[4.0, 3.0, 0.5, 2.0], SHAPE=[2,2])
  N = 2
  NCOLS = 2
  LDA = 2
  LDAF = 2

  result = SLA_GERPVGRW(N, NCOLS, A, LDA, AF, LDAF)

  PRINT *, "Reciprocal Pivot Growth Factor: ", result
END PROGRAM test_sla_gerpvgrw

REAL FUNCTION SLA_GERPVGRW(N, NCOLS, A, LDA, AF, LDAF)
  INTEGER, INTENT(IN) :: N, NCOLS, LDA, LDAF
  REAL, INTENT(IN) :: A(LDA, *), AF(LDAF, *)
  INTEGER :: I, J
  REAL :: AMAX, UMAX, RPVGRW
  RPVGRW = 1.0

  DO J = 1, NCOLS
     AMAX = 0.0
     UMAX = 0.0
     DO I = 1, N
        AMAX = MAX(ABS(A(I, J)), AMAX)
     END DO
     DO I = 1, J
        UMAX = MAX(ABS(AF(I, J)), UMAX)
     END DO
     IF (UMAX /= 0.0) THEN
        RPVGRW = MIN(AMAX / UMAX, RPVGRW)
     END IF
  END DO
  SLA_GERPVGRW = RPVGRW
END FUNCTION SLA_GERPVGRW