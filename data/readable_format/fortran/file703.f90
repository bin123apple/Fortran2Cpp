MODULE geoutg_mod
  IMPLICIT NONE
CONTAINS
  SUBROUTINE geoutg(IPRT)
    INTEGER, INTENT(IN) :: IPRT
    PRINT *, 'IPRT = ', IPRT
  END SUBROUTINE geoutg
END MODULE geoutg_mod

PROGRAM test_geoutg
  USE geoutg_mod
  IMPLICIT NONE
  INTEGER :: IPRT
  
  ! Example usage of geoutg subroutine
  IPRT = 5
  CALL geoutg(IPRT)
  
END PROGRAM test_geoutg