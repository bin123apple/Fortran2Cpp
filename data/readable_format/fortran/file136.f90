PROGRAM testAGCHIL
  IMPLICIT NONE

  CALL AGCHIL(1, 'TestLabel', 2)

  PRINT *, 'AGCHIL called successfully.'

CONTAINS

  SUBROUTINE AGCHIL (IFLG,LBNM,LNNO)
    INTEGER, INTENT(IN) :: IFLG, LNNO
    CHARACTER*(*) :: LBNM
    ! Since the subroutine does nothing, there's nothing to test here.
    RETURN
  END SUBROUTINE AGCHIL

END PROGRAM testAGCHIL