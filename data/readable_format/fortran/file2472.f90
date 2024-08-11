MODULE vast_kind_param
  INTEGER, PARAMETER :: DOUBLE = SELECTED_REAL_KIND(15, 307)
END MODULE vast_kind_param

MODULE drcout_I
  INTERFACE
    SUBROUTINE drcout(XYZ3, GEO3, VEL3, NVAR, TIME, ESCF3, EKIN3, ETOT3, XTOT3, ILOOP, CHARGE, FRACT, TEXT1, TEXT2, II, JLOOP)
      USE vast_kind_param, ONLY: DOUBLE
      INTEGER, INTENT(IN) :: NVAR
      REAL(DOUBLE), DIMENSION(3, NVAR), INTENT(IN) :: XYZ3
      REAL(DOUBLE), DIMENSION(3, NVAR), INTENT(IN) :: GEO3
      REAL(DOUBLE), DIMENSION(3, NVAR), INTENT(IN) :: VEL3
      REAL(DOUBLE), INTENT(IN) :: TIME
      REAL(DOUBLE), DIMENSION(3), INTENT(IN) :: ESCF3
      REAL(DOUBLE), DIMENSION(3), INTENT(IN) :: EKIN3
      REAL(DOUBLE), DIMENSION(3), INTENT(IN) :: ETOT3
      REAL(DOUBLE), DIMENSION(3), INTENT(IN) :: XTOT3
      INTEGER, INTENT(IN) :: ILOOP
      REAL(DOUBLE), DIMENSION(:), INTENT(IN) :: CHARGE
      REAL(DOUBLE), INTENT(IN) :: FRACT
      CHARACTER (LEN = 3), INTENT(IN) :: TEXT1
      CHARACTER (LEN = 2), INTENT(IN) :: TEXT2
      INTEGER, INTENT(IN) :: II
      INTEGER, INTENT(INOUT) :: JLOOP
    END SUBROUTINE drcout
  END INTERFACE
END MODULE drcout_I

PROGRAM test_drcout
  USE drcout_I
  USE vast_kind_param, ONLY: DOUBLE
  IMPLICIT NONE

  INTEGER :: NVAR, ILOOP, II, JLOOP
  REAL(DOUBLE) :: TIME, FRACT
  REAL(DOUBLE), DIMENSION(3, 3) :: XYZ3, GEO3, VEL3
  REAL(DOUBLE), DIMENSION(3) :: ESCF3, EKIN3, ETOT3, XTOT3
  REAL(DOUBLE), DIMENSION(3) :: CHARGE
  CHARACTER(LEN=3) :: TEXT1
  CHARACTER(LEN=2) :: TEXT2

  ! Initialize variables
  NVAR = 3
  XYZ3 = RESHAPE((/ 1.0D0, 2.0D0, 3.0D0, 4.0D0, 5.0D0, 6.0D0, 7.0D0, 8.0D0, 9.0D0 /), (/ 3, 3 /))
  GEO3 = RESHAPE((/ 1.1D0, 2.1D0, 3.1D0, 4.1D0, 5.1D0, 6.1D0, 7.1D0, 8.1D0, 9.1D0 /), (/ 3, 3 /))
  VEL3 = RESHAPE((/ 0.1D0, 0.2D0, 0.3D0, 0.4D0, 0.5D0, 0.6D0, 0.7D0, 0.8D0, 0.9D0 /), (/ 3, 3 /))
  TIME = 10.0D0
  ESCF3 = (/ 1.0D0, 2.0D0, 3.0D0 /)
  EKIN3 = (/ 4.0D0, 5.0D0, 6.0D0 /)
  ETOT3 = (/ 7.0D0, 8.0D0, 9.0D0 /)
  XTOT3 = (/ 10.0D0, 11.0D0, 12.0D0 /)
  ILOOP = 2
  CHARGE = (/ 0.5D0, 0.6D0, 0.7D0 /)
  FRACT = 0.3D0
  TEXT1 = 'ABC'
  TEXT2 = 'XY'
  II = 1
  JLOOP = 0

  CALL drcout(XYZ3, GEO3, VEL3, NVAR, TIME, ESCF3, EKIN3, ETOT3, XTOT3, ILOOP, CHARGE, FRACT, TEXT1, TEXT2, II, JLOOP)

END PROGRAM test_drcout

SUBROUTINE drcout(XYZ3, GEO3, VEL3, NVAR, TIME, ESCF3, EKIN3, ETOT3, XTOT3, ILOOP, CHARGE, FRACT, TEXT1, TEXT2, II, JLOOP)
  USE vast_kind_param, ONLY: DOUBLE
  INTEGER, INTENT(IN) :: NVAR
  REAL(DOUBLE), DIMENSION(3, NVAR), INTENT(IN) :: XYZ3
  REAL(DOUBLE), DIMENSION(3, NVAR), INTENT(IN) :: GEO3
  REAL(DOUBLE), DIMENSION(3, NVAR), INTENT(IN) :: VEL3
  REAL(DOUBLE), INTENT(IN) :: TIME
  REAL(DOUBLE), DIMENSION(3), INTENT(IN) :: ESCF3
  REAL(DOUBLE), DIMENSION(3), INTENT(IN) :: EKIN3
  REAL(DOUBLE), DIMENSION(3), INTENT(IN) :: ETOT3
  REAL(DOUBLE), DIMENSION(3), INTENT(IN) :: XTOT3
  INTEGER, INTENT(IN) :: ILOOP
  REAL(DOUBLE), DIMENSION(:), INTENT(IN) :: CHARGE
  REAL(DOUBLE), INTENT(IN) :: FRACT
  CHARACTER (LEN = 3), INTENT(IN) :: TEXT1
  CHARACTER (LEN = 2), INTENT(IN) :: TEXT2
  INTEGER, INTENT(IN) :: II
  INTEGER, INTENT(INOUT) :: JLOOP

  PRINT *, 'XYZ3:'
  DO i = 1, NVAR
    PRINT *, XYZ3(:, i)
  END DO

  PRINT *, 'GEO3:'
  DO i = 1, NVAR
    PRINT *, GEO3(:, i)
  END DO

  PRINT *, 'VEL3:'
  DO i = 1, NVAR
    PRINT *, VEL3(:, i)
  END DO

  PRINT *, 'TIME:', TIME
  PRINT *, 'ESCF3:', ESCF3
  PRINT *, 'EKIN3:', EKIN3
  PRINT *, 'ETOT3:', ETOT3
  PRINT *, 'XTOT3:', XTOT3
  PRINT *, 'ILOOP:', ILOOP

  PRINT *, 'CHARGE:'
  DO i = 1, 3
    PRINT *, CHARGE(i)
  END DO

  PRINT *, 'FRACT:', FRACT
  PRINT *, 'TEXT1:', TEXT1
  PRINT *, 'TEXT2:', TEXT2
  PRINT *, 'II:', II
  PRINT *, 'JLOOP:', JLOOP

END SUBROUTINE drcout