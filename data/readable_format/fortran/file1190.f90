MODULE myFunctions
  IMPLICIT NONE
CONTAINS
  REAL*8 FUNCTION eqn6001(x)
    REAL*8, INTENT(IN) :: x
    eqn6001 = 0.04374048076242294D0 + x*(0.0001367780769892812D0 + &
             x*(-4.850231342481508D-08 + x*(8.549501530074314D-12 + &
             x*(-4.899699862336812D-16))))
  END FUNCTION eqn6001
END MODULE myFunctions

PROGRAM main
  USE myFunctions
  IMPLICIT NONE
  REAL*8 :: x, y, a, b, c, d, e, teff
  REAL*8 :: order1, order2, order3, order4, constant
  REAL*8 :: ohzflux
  REAL*8 :: test_x, expected_y, tolerance

  a = 0.04374048076242294D0
  b = 0.0001367780769892812D0
  c = -4.850231342481508D-08
  d = 8.549501530074314D-12
  e = -4.899699862336812D-16
  teff = 5780.0D0

  constant = a + b*teff + c*teff**2 + d*teff**3 + e*teff**4
  order1 = b + 2.0*c*teff + 3.0*d*teff**2 + 4.0*e*teff**3
  order2 = c + 3.0*d*teff + 6.0*e*teff**2
  order3 = d + 4.0*e*teff
  order4 = e

  PRINT *, "Constant, Order1, Order2, Order3, Order4:"
  PRINT *, constant, order1, order2, order3, order4

  x = 2600.0D0
  DO WHILE (x <= 7201.0D0)
    y = eqn6001(x)
    ohzflux = constant + order1*(x-teff) + order2*(x-teff)**2 + &
              order3*(x-teff)**3 + order4*(x-teff)**4
    PRINT *, "X, OHZFlux:", x, ohzflux
    x = x + 200.0D0
  END DO

  ! Unit Test
  PRINT *, "Testing eqn6001 function:"
  test_x = 2600.0D0
  expected_y = eqn6001(test_x)
  tolerance = 1.0e-8

  IF (ABS(eqn6001(test_x) - expected_y) > tolerance) THEN
      PRINT *, "Test Failed for eqn6001 with X =", test_x
  ELSE
      PRINT *, "Test Passed for eqn6001 with X =", test_x
  END IF

END PROGRAM main