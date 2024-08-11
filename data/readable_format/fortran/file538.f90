PROGRAM test_constants
  USE iso_fortran_env, ONLY: REAL64
  IMPLICIT NONE
  REAL(KIND=REAL64), PARAMETER :: pi = 3.141592653589_REAL64, &
                                  eps0 = 8.8541878176E-12_REAL64, &
                                  mu0 = 4*pi*1E-7_REAL64, &
                                  c0 = 2.997924580003E8_REAL64, &
                                  eta0 = 3.767303134622E2_REAL64
  REAL(KIND=REAL64), PARAMETER :: radtodeg = 180.0_REAL64/pi, &
                                  degtorad = pi/180.0_REAL64
  INTEGER, PARAMETER :: prd_none = 1, prd_2d = 2

  ! Test constants
  PRINT *, "Testing constants..."
  CALL testValue(pi, 3.141592653589_REAL64, "pi")
  CALL testValue(eps0, 8.8541878176E-12_REAL64, "eps0")
  CALL testValue(mu0, 4*pi*1E-7_REAL64, "mu0")
  CALL testValue(c0, 2.997924580003E8_REAL64, "c0")
  CALL testValue(eta0, 3.767303134622E2_REAL64, "eta0")
  CALL testValue(radtodeg, 180.0_REAL64/pi, "radtodeg")
  CALL testValue(degtorad, pi/180.0_REAL64, "degtorad")
  PRINT *, "Testing integer parameters..."
  CALL testInt(prd_none, 1, "prd_none")
  CALL testInt(prd_2d, 2, "prd_2d")

CONTAINS

  SUBROUTINE testValue(value, expected, name)
    REAL(KIND=REAL64), INTENT(IN) :: value, expected
    CHARACTER(len=*), INTENT(IN) :: name
    REAL(KIND=REAL64) :: diff
    diff = ABS(value - expected)
    IF (diff > 1.0E-12_REAL64) THEN
      PRINT *, "Test for ", name, " failed!"
    ELSE
      PRINT *, "Test for ", name, " passed."
    END IF
  END SUBROUTINE testValue

  SUBROUTINE testInt(value, expected, name)
    INTEGER, INTENT(IN) :: value, expected
    CHARACTER(len=*), INTENT(IN) :: name
    IF (value /= expected) THEN
      PRINT *, "Integer test for ", name, " failed!"
    ELSE
      PRINT *, "Integer test for ", name, " passed."
    END IF
  END SUBROUTINE testInt

END PROGRAM test_constants