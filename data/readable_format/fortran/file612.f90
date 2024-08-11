PROGRAM testFindR1
  IMPLICIT NONE
  REAL :: list(5) = [1.0, 2.0, 3.0, 4.0, 5.0]
  INTEGER :: result
  
  ! Test finding an element at the beginning
  result = FINDR1(1.0, 5, list)
  IF (result == 1) THEN
    PRINT *, "Test 1 Passed."
  ELSE
    PRINT *, "Test 1 Failed."
  END IF

  ! Test finding an element in the middle
  result = FINDR1(3.0, 5, list)
  IF (result == 3) THEN
    PRINT *, "Test 2 Passed."
  ELSE
    PRINT *, "Test 2 Failed."
  END IF

  ! Test finding an element at the end
  result = FINDR1(5.0, 5, list)
  IF (result == 5) THEN
    PRINT *, "Test 3 Passed."
  ELSE
    PRINT *, "Test 3 Failed."
  END IF

  ! Test not finding an element
  result = FINDR1(6.0, 5, list)
  IF (result == -1) THEN
    PRINT *, "Test 4 Passed."
  ELSE
    PRINT *, "Test 4 Failed."
  END IF

CONTAINS

  INTEGER FUNCTION FINDR1(K, N, LIST)
    REAL, INTENT(IN) :: K
    INTEGER, INTENT(IN) :: N
    REAL, INTENT(IN) :: LIST(N)
    INTEGER :: LO, HI, M

    LO = 1
    HI = N

    DO WHILE (LO <= HI)
      M = (LO + HI) / 2
      IF (K > LIST(M)) THEN
        LO = M + 1
      ELSE IF (K < LIST(M)) THEN
        HI = M - 1
      ELSE
        FINDR1 = M
        RETURN
      END IF
    END DO

    FINDR1 = -1
  END FUNCTION FINDR1

END PROGRAM testFindR1