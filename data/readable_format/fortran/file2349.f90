MODULE IceFloe_Types
! Since we're not using a separate 'precision' module, we define precision directly.
! Assuming double precision for real numbers.
IMPLICIT NONE
  INTEGER, PARAMETER :: ReKi = SELECTED_REAL_KIND(15, 307)
  INTEGER, PARAMETER :: IntKi = SELECTED_INT_KIND(10)

  TYPE, PUBLIC :: IceFloe_ParameterType
    REAL(ReKi) , DIMENSION(:,:), ALLOCATABLE  :: loadSeries
    REAL(ReKi)  :: iceVel
    REAL(ReKi)  :: iceDirection
    REAL(ReKi)  :: minStrength
    REAL(ReKi)  :: minStrengthNegVel
    REAL(ReKi)  :: defaultArea
    REAL(ReKi)  :: crushArea
    REAL(ReKi)  :: coeffStressRate
    REAL(ReKi)  :: C(4)
    REAL(ReKi)  :: dt
    REAL(ReKi)  :: rampTime
    REAL(ReKi) , DIMENSION(:), ALLOCATABLE  :: legX
    REAL(ReKi) , DIMENSION(:), ALLOCATABLE  :: legY
    REAL(ReKi) , DIMENSION(:), ALLOCATABLE  :: ks
    INTEGER(IntKi)  :: numLegs
    INTEGER(IntKi)  :: iceType
    INTEGER(IntKi)  :: logUnitNum
    LOGICAL  :: singleLoad
    LOGICAL  :: initFlag
  END TYPE IceFloe_ParameterType

  ! Constants
  REAL(ReKi), PARAMETER :: Pi  = 3.14159265358979323846_ReKi
  REAL(ReKi), PARAMETER :: D2R = Pi/180.0_ReKi
  REAL(ReKi), PARAMETER :: R2D = 180.0_ReKi/Pi

END MODULE IceFloe_Types

PROGRAM TestIceFloe
  USE IceFloe_Types
  IMPLICIT NONE

  TYPE(IceFloe_ParameterType) :: iceFloeParams

  ! Initialize some values
  iceFloeParams%iceVel = 5.0_ReKi
  iceFloeParams%iceDirection = 90.0_ReKi * D2R
  iceFloeParams%minStrength = 1.0_ReKi
  iceFloeParams%singleLoad = .TRUE.
  iceFloeParams%initFlag = .FALSE.

  ! Print some values to validate
  PRINT *, 'Ice Velocity: ', iceFloeParams%iceVel
  PRINT *, 'Ice Direction (rad): ', iceFloeParams%iceDirection
  PRINT *, 'Ice Direction (deg): ', iceFloeParams%iceDirection * R2D

END PROGRAM TestIceFloe