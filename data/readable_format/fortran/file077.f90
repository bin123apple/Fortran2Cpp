MODULE ovlp_I
  IMPLICIT NONE
  CONTAINS
  SUBROUTINE ovlp(IC)
    INTEGER, INTENT(IN) :: IC
    PRINT *, 'Doubled value is:', IC * 2
  END SUBROUTINE ovlp
END MODULE ovlp_I

PROGRAM testOvlp
  USE ovlp_I
  IMPLICIT NONE
  INTEGER :: testVal
  
  testVal = 5 ! Example test value
  CALL ovlp(testVal)
END PROGRAM testOvlp