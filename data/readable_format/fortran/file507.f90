PROGRAM testIauCP
  IMPLICIT NONE
  DOUBLE PRECISION P(3), C(3)
  INTEGER I
  LOGICAL :: success

  ! Initialize array P
  P(1) = 1.0
  P(2) = 2.0
  P(3) = 3.0

  ! Call the subroutine
  CALL iau_CP(P, C)

  ! Check if C is a copy of P
  success = .TRUE.
  DO I = 1, 3
    IF (C(I) .NE. P(I)) THEN
      success = .FALSE.
    END IF
  END DO

  IF (success) THEN
    PRINT *, 'Test Passed: C is a copy of P.'
  ELSE
    PRINT *, 'Test Failed: C is not a copy of P.'
  END IF

END PROGRAM testIauCP

SUBROUTINE iau_CP ( P, C )
  IMPLICIT NONE
  DOUBLE PRECISION P(3), C(3)
  INTEGER I
  DO I=1,3
     C(I) = P(I)
  END DO
END SUBROUTINE iau_CP