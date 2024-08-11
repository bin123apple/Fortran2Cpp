MODULE IZAMAX__genmod
  IMPLICIT NONE
CONTAINS
  FUNCTION IZAMAX(N,ZX,INCX) RESULT(idx)
    INTEGER(KIND=4), INTENT(IN) :: N
    COMPLEX(KIND=8), INTENT(IN) :: ZX(*)
    INTEGER(KIND=4), INTENT(IN) :: INCX
    INTEGER(KIND=4) :: idx
    REAL(KIND=8) :: max_val
    INTEGER(KIND=4) :: i

    idx = 1
    max_val = ABS(ZX(1))
    DO i = 2, N, INCX
      IF (ABS(ZX(i)) > max_val) THEN
        max_val = ABS(ZX(i))
        idx = i
      END IF
    END DO
  END FUNCTION IZAMAX
END MODULE IZAMAX__genmod

PROGRAM test_IZAMAX
  USE IZAMAX__genmod
  IMPLICIT NONE
  INTEGER(KIND=4) :: result
  COMPLEX(KIND=8), DIMENSION(5) :: arr
  INTEGER(KIND=4) :: i

  ! Initialize complex array with some values
  DO i = 1, 5
    arr(i) = COMPLEX(i*1.0, i*2.0)
  END DO

  result = IZAMAX(5, arr, 1)
  PRINT *, "The index of max abs value is: ", result
END PROGRAM test_IZAMAX