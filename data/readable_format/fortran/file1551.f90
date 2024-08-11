PROGRAM TESTFOO
  IMPLICIT NONE
  INTEGER, DIMENSION(4) :: IBUFR
  CHARACTER(LEN=4) :: VALUE

  ! Initialize the buffer with ASCII values for 'ABCD'
  IBUFR = (/65, 66, 67, 68/)

  CALL FOO(IBUFR, VALUE)

  PRINT *, 'Test Result: ', VALUE

CONTAINS

  SUBROUTINE FOO(IBUFR, VALUE)
    INTEGER, INTENT(IN) :: IBUFR(4)
    CHARACTER(LEN=4), INTENT(OUT) :: VALUE
    INTEGER :: I

    VALUE = ''
    DO I = 1, 4
      VALUE(I:I) = CHAR(IBUFR(I))
    END DO
  END SUBROUTINE FOO

END PROGRAM TESTFOO