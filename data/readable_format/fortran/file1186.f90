PROGRAM Main
  IMPLICIT NONE
  
  ! Declare variables for the test case
  INTEGER(KIND=4) :: NPHI, NTHETA
  REAL(KIND=8) :: LON, LAT, CAP_DEGREE
  REAL(KIND=8), ALLOCATABLE :: XLON(:), XLAT(:), WEIGHT(:)
  
  ! Initialize variables
  LON = 0.0D0
  LAT = 0.0D0
  CAP_DEGREE = 1.0D0
  NTHETA = 2
  NPHI = 2
  ALLOCATE(XLON(NTHETA*NPHI), XLAT(NTHETA*NPHI), WEIGHT(NTHETA*NPHI))
  
  XLON = [0.0D0, 1.0D0, 0.0D0, 1.0D0]
  XLAT = [0.0D0, 0.0D0, 1.0D0, 1.0D0]
  WEIGHT = [0.0D0, 0.0D0, 0.0D0, 0.0D0]  ! Assuming initial weights are zero
  
  ! Call the subroutine
  CALL SMOOTH_WEIGHTS_CAP_VARDEGREE(LON, LAT, XLON, XLAT, WEIGHT, CAP_DEGREE, NTHETA, NPHI)
  
  ! Output results for verification
  PRINT *, "WEIGHTS:", WEIGHT
  
  DEALLOCATE(XLON, XLAT, WEIGHT)

CONTAINS

  SUBROUTINE SMOOTH_WEIGHTS_CAP_VARDEGREE(LON, LAT, XLON, XLAT,  &
       WEIGHT, CAP_DEGREE, NTHETA, NPHI)
    INTEGER(KIND=4), INTENT(IN) :: NPHI, NTHETA
    REAL(KIND=8), INTENT(IN) :: LON, LAT, CAP_DEGREE
    REAL(KIND=8), INTENT(IN) :: XLON(NTHETA*NPHI), XLAT(NTHETA*NPHI)
    REAL(KIND=8), INTENT(OUT) :: WEIGHT(NTHETA*NPHI)
    
    ! For demonstration, let's simply set each weight to a constant value
    ! In a real scenario, you would replace this with your actual computation
    WEIGHT = 1.0D0  ! Example computation
  END SUBROUTINE SMOOTH_WEIGHTS_CAP_VARDEGREE

END PROGRAM Main