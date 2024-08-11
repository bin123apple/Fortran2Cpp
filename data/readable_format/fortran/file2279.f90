PROGRAM test_main
  IMPLICIT NONE
  CALL run_test()
CONTAINS
  SUBROUTINE run_test()
    TYPE :: test_typ
      REAL, ALLOCATABLE :: a
    END TYPE
    TYPE(test_typ) :: my_test_typ
    my_test_typ = test_typ (a = 1.0)
    if (abs(my_test_typ%a - 1.0) .gt. 1e-6) THEN
      PRINT *, "Test failed!"
      STOP 1
    ELSE
      PRINT *, "Test passed!"
    END IF
  END SUBROUTINE run_test
END PROGRAM test_main