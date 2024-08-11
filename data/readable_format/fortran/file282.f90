MODULE RefMod
  IMPLICIT NONE
CONTAINS
  FUNCTION REF(A) RESULT(B)
    REAL(8) :: A, B
    B = A + A
    RETURN
  END FUNCTION REF
END MODULE RefMod

PROGRAM TestRefFunction
  USE RefMod
  IMPLICIT NONE
  REAL(8) :: result

  ! Test 1
  result = REF(2.0_8)
  IF (result == 4.0_8) THEN
    PRINT *, "Test 1 Passed: REF(2.0) = 4.0"
  ELSE
    PRINT *, "Test 1 Failed: REF(2.0) = ", result
  END IF

  ! Test 2
  result = REF(-1.0_8)
  IF (result == -2.0_8) THEN
    PRINT *, "Test 2 Passed: REF(-1.0) = -2.0"
  ELSE
    PRINT *, "Test 2 Failed: REF(-1.0) = ", result
  END IF
END PROGRAM TestRefFunction