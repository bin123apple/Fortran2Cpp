PROGRAM TestV7CPY
  IMPLICIT NONE
  INTEGER :: P
  PARAMETER (P=5)
  REAL :: X(P), Y(P)
  INTEGER :: I

! Initialize array X with test data and Y with zeros
  DO I = 1, P
    X(I) = REAL(I)
    Y(I) = 0.0
  END DO

! Call the V7CPY subroutine to copy X to Y
  CALL V7CPY(P, Y, X)

! Check and print results
  DO I = 1, P
    IF (Y(I) /= X(I)) THEN
      PRINT *, 'Test Failed: Y(I) /= X(I) for I =', I
      STOP
    END IF
  END DO

  PRINT *, 'Test Passed: All elements copied correctly.'

END PROGRAM TestV7CPY

SUBROUTINE V7CPY(P, Y, X)
  INTEGER, INTENT(IN) :: P
  REAL, INTENT(IN) :: X(P)
  REAL, INTENT(OUT) :: Y(P)
  INTEGER :: I
  DO I = 1, P
    Y(I) = X(I)
  END DO
END SUBROUTINE V7CPY