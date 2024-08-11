PROGRAM testSIDEP
  IMPLICIT NONE
  LOGICAL :: res
  DOUBLE PRECISION :: test_angles(3)
  INTEGER :: i

  ! Declare the function at the beginning of your program
  INTERFACE
    LOGICAL FUNCTION SIDEP(ANGLE)
      DOUBLE PRECISION, INTENT(IN) :: ANGLE
    END FUNCTION SIDEP
  END INTERFACE

  ! Initialize test angles
  DATA test_angles /0.0, 3.14159265358979323846, 6.28318530717958647692/

  ! Run tests
  DO i = 1, SIZE(test_angles)
     res = SIDEP(test_angles(i))
     PRINT *, 'ANGLE = ', test_angles(i), ' RESULT = ', res
  END DO

END PROGRAM testSIDEP

LOGICAL FUNCTION SIDEP (ANGLE)
  DOUBLE PRECISION, INTENT(IN) :: ANGLE
  DOUBLE PRECISION :: EPS, PI
  EPS = 1.27
  PI = ATAN2(0.0, -1.0)
  IF ((ANGLE .GT. (PI - EPS)) .AND. (ANGLE .LT. (PI + EPS))) THEN
     SIDEP = .TRUE.
  ELSE
     SIDEP = .FALSE.
  ENDIF
  RETURN
END FUNCTION SIDEP