MODULE TT
  CONTAINS
    ELEMENTAL REAL FUNCTION two(N)
      INTEGER, INTENT(IN) :: N
      two = REAL(N) * 2.0
    END FUNCTION two

    ELEMENTAL REAL FUNCTION twopointfive(N)
      INTEGER, INTENT(IN) :: N
      twopointfive = REAL(N) * 2.5
    END FUNCTION twopointfive
END MODULE TT

PROGRAM TestTT
  USE TT
  IMPLICIT NONE
  INTEGER :: i
  PRINT *, "Testing function 'two':"
  DO i = 1, 5
    PRINT *, "two(", i, ") = ", two(i)
  END DO

  PRINT *, "Testing function 'twopointfive':"
  DO i = 1, 5
    PRINT *, "twopointfive(", i, ") = ", twopointfive(i)
  END DO
END PROGRAM TestTT