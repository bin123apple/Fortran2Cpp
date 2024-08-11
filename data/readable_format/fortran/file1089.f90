PROGRAM TestIau_OBL06
  IMPLICIT NONE

  DOUBLE PRECISION :: DATE1, DATE2, result, expected, tolerance

  DATE1 = 2451545.0D0
  DATE2 = 0.0D0
  expected = 0.40909260060058289D0
  tolerance = 1.0D-12

  result = iau_OBL06(DATE1, DATE2)

  IF (ABS(result - expected) .LT. tolerance) THEN
    PRINT *, 'Fortran Test passed.'
  ELSE
    PRINT *, 'Fortran Test failed.'
    PRINT *, 'Expected:', expected
    PRINT *, 'Got:', result
  END IF

CONTAINS

  DOUBLE PRECISION FUNCTION iau_OBL06(DATE1, DATE2)
    IMPLICIT NONE
    DOUBLE PRECISION, INTENT(IN) :: DATE1, DATE2
    DOUBLE PRECISION, PARAMETER :: DAS2R = 4.848136811095359935899141D-6
    DOUBLE PRECISION, PARAMETER :: DJ00 = 2451545D0
    DOUBLE PRECISION, PARAMETER :: DJC = 36525D0
    DOUBLE PRECISION :: T

    T = ((DATE1 - DJ00) + DATE2) / DJC

    iau_OBL06 = (84381.406D0 + &
                 (-46.836769D0 + &
                 (-0.0001831D0 + &
                 (0.00200340D0 + &
                 (-0.000000576D0 + &
                 (-0.0000000434D0) * T) * T) * T) * T) * T) * DAS2R
  END FUNCTION iau_OBL06

END PROGRAM TestIau_OBL06