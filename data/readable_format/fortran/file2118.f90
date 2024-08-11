MODULE dihed_I
  IMPLICIT NONE
  INTEGER, PARAMETER :: dp = KIND(1.0D0)
CONTAINS
  SUBROUTINE dihed(XYZ, I, J, K, L, ANGLE)
    REAL(KIND=dp), DIMENSION(3,*), INTENT(IN) :: XYZ
    INTEGER, INTENT(IN) :: I, J, K, L
    REAL(KIND=dp), INTENT(INOUT) :: ANGLE
    REAL(KIND=dp) :: dx, dy, dz

    dx = XYZ(1, I) - XYZ(1, J)
    dy = XYZ(2, K) - XYZ(2, L)
    dz = XYZ(3, I) - XYZ(3, L)
    ANGLE = SQRT(dx*dx + dy*dy + dz*dz)
  END SUBROUTINE dihed
END MODULE dihed_I

PROGRAM test_dihed
  USE dihed_I
  IMPLICIT NONE

  REAL(KIND=dp), DIMENSION(3,4) :: XYZ
  INTEGER :: I, J, K, L
  REAL(KIND=dp) :: ANGLE

  XYZ = RESHAPE([0.0_dp, 1.0_dp, 2.0_dp, &
                 3.0_dp, 4.0_dp, 5.0_dp, &
                 6.0_dp, 7.0_dp, 8.0_dp, &
                 9.0_dp, 10.0_dp, 11.0_dp], SHAPE(XYZ))
  I = 1
  J = 2
  K = 3
  L = 2
  CALL dihed(XYZ, I, J, K, L, ANGLE)

  PRINT *, 'ANGLE:', ANGLE

END PROGRAM test_dihed