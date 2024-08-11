MODULE CONTROLRET
  IMPLICIT NONE
CONTAINS
  FUNCTION increment(n)
    INTEGER, INTENT(IN) :: n
    INTEGER :: increment
    increment = n + 1
  END FUNCTION increment
END MODULE CONTROLRET

SUBROUTINE NDTRAN(n, result)
  USE CONTROLRET
  INTEGER, INTENT(IN) :: n
  INTEGER, INTENT(OUT) :: result
  result = increment(n)
END SUBROUTINE NDTRAN

PROGRAM testNDTRAN
  USE CONTROLRET
  INTEGER :: input, output
  input = 5
  CALL NDTRAN(input, output)
  PRINT *, 'Input:', input, ' Output:', output
END PROGRAM testNDTRAN