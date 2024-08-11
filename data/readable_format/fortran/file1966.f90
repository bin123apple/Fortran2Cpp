MODULE type_definitions
  TYPE :: type1
    INTEGER :: v
  END TYPE type1
END MODULE type_definitions

PROGRAM MAIN
  USE type_definitions
  IMPLICIT NONE
  TYPE(type1) :: a

  a%v = 1
  CALL test_type1(a)
  
CONTAINS

  SUBROUTINE test_type1(a)
    TYPE(type1), INTENT(IN) :: a
    IF (a%v == 1) THEN
      PRINT *, "test_type1 passed."
    ELSE
      PRINT *, "test_type1 failed."
    END IF
  END SUBROUTINE test_type1

END PROGRAM MAIN