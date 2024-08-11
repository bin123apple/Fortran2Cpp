MODULE mod_tides
  IMPLICIT NONE
CONTAINS
  FUNCTION add_integers(a, b)
    INTEGER, INTENT(IN) :: a, b
    INTEGER :: add_integers
    add_integers = a + b
  END FUNCTION add_integers
END MODULE mod_tides

PROGRAM testModTides
  USE mod_tides
  IMPLICIT NONE
  INTEGER :: result

  result = add_integers(2, 3)
  PRINT *, "Result of adding 2 and 3 is: ", result
END PROGRAM testModTides