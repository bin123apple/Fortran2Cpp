PROGRAM test_norm_rot
  IMPLICIT NONE
  REAL(KIND=8) :: THN, PHN, TH, PH, TH_NEW, PH_NEW

  ! Initialize input values
  THN = 1.0
  PHN = 2.0
  TH = 3.0
  PH = 4.0

  ! Call the subroutine
  CALL NORM_ROT(THN, PHN, TH, PH, TH_NEW, PH_NEW)

  ! Check the results
  IF (TH_NEW == TH .AND. PH_NEW == PH) THEN
    PRINT *, "Test Passed."
  ELSE
    PRINT *, "Test Failed."
  END IF

CONTAINS

  SUBROUTINE NORM_ROT(THN, PHN, TH, PH, TH_NEW, PH_NEW)
    REAL(KIND=8), INTENT(IN) :: THN, PHN, TH, PH
    REAL(KIND=8), INTENT(OUT) :: TH_NEW, PH_NEW

    ! Your subroutine logic here
    ! For demonstration, simply copy inputs to outputs
    TH_NEW = TH
    PH_NEW = PH

  END SUBROUTINE NORM_ROT

END PROGRAM test_norm_rot