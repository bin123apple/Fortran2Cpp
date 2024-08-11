PROGRAM testZEXP
  IMPLICIT NONE
  DOUBLE PRECISION :: AR, AI, BR, BI

  ! Test 1
  CALL test_case(1.0D0, 0.0D0)

  ! Test 2
  CALL test_case(0.0D0, 1.0D0)

  ! Test 3
  CALL test_case(-1.0D0, -1.0D0)

  ! Test 4
  CALL test_case(0.5D0, 0.5D0)

CONTAINS

  SUBROUTINE ZEXP(AR, AI, BR, BI)
    DOUBLE PRECISION AR, AI, BR, BI, ZM, CA, CB
    ZM = EXP(AR)
    CA = ZM*COS(AI)
    CB = ZM*SIN(AI)
    BR = CA
    BI = CB
  END SUBROUTINE ZEXP

  SUBROUTINE test_case(AR, AI)
    DOUBLE PRECISION, INTENT(IN) :: AR, AI
    DOUBLE PRECISION :: BR, BI

    CALL ZEXP(AR, AI, BR, BI)
    PRINT *, 'For input (', AR, ',', AI, ') -> exp is (', BR, ',', BI, ')'
  END SUBROUTINE test_case

END PROGRAM testZEXP