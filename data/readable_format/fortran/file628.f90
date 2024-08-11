PROGRAM TestDM2AV
  IMPLICIT NONE
  DOUBLE PRECISION RMAT(3,3), AXVEC(3)
  DOUBLE PRECISION, PARAMETER :: TOL = 1.0E-12
  INTEGER :: i

  ! Define a test rotation matrix (identity matrix)
  RMAT = RESHAPE((/1D0, 0D0, 0D0, 0D0, 1D0, 0D0, 0D0, 0D0, 1D0/), (/3,3/))

  ! Call the subroutine
  CALL sla_DM2AV(RMAT, AXVEC)

  ! Expected axis vector should be [0, 0, 0] for an identity matrix
  DO i = 1, 3
     IF (ABS(AXVEC(i)) > TOL) THEN
        PRINT *, 'Test failed for element', i, 'Value:', AXVEC(i)
        STOP
     END IF
  END DO

  PRINT *, 'Test passed successfully.'

END PROGRAM TestDM2AV

SUBROUTINE sla_DM2AV(RMAT, AXVEC)
  IMPLICIT NONE
  DOUBLE PRECISION RMAT(3,3), AXVEC(3)
  DOUBLE PRECISION X,Y,Z,S2,C2,PHI,F

  X = RMAT(2,3)-RMAT(3,2)
  Y = RMAT(3,1)-RMAT(1,3)
  Z = RMAT(1,2)-RMAT(2,1)
  S2 = SQRT(X*X+Y*Y+Z*Z)
  IF (S2.NE.0D0) THEN
     C2 = RMAT(1,1)+RMAT(2,2)+RMAT(3,3)-1D0
     PHI = ATAN2(S2,C2)
     F = PHI/S2
     AXVEC(1) = X*F
     AXVEC(2) = Y*F
     AXVEC(3) = Z*F
  ELSE
     AXVEC(1) = 0D0
     AXVEC(2) = 0D0
     AXVEC(3) = 0D0
  END IF

END SUBROUTINE sla_DM2AV