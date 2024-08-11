PROGRAM testSB02MV
  IMPLICIT NONE

  DOUBLE PRECISION :: reig_positive = 1.0D0
  DOUBLE PRECISION :: reig_negative = -1.0D0
  DOUBLE PRECISION :: ieig = 0.0D0
  LOGICAL :: result

  ! Test with positive REIG
  result = SB02MV(reig_positive, ieig)
  IF (result) THEN
    PRINT *, "Test with positive REIG failed."
  ELSE
    PRINT *, "Test with positive REIG passed."
  END IF

  ! Test with negative REIG
  result = SB02MV(reig_negative, ieig)
  IF (result) THEN
    PRINT *, "Test with negative REIG passed."
  ELSE
    PRINT *, "Test with negative REIG failed."
  END IF

CONTAINS

  LOGICAL FUNCTION SB02MV(REIG, IEIG)
    DOUBLE PRECISION, INTENT(IN) :: REIG, IEIG
    SB02MV = REIG < 0.0D0
  END FUNCTION SB02MV

END PROGRAM testSB02MV