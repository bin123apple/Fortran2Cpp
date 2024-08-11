MODULE SCASUM_MOD
  IMPLICIT NONE
CONTAINS
  REAL FUNCTION SCASUM(N,CX,INCX)
    INTEGER, INTENT(IN) :: N, INCX
    COMPLEX, INTENT(IN) :: CX(*)
    REAL :: STEMP
    INTEGER :: I, NINCX

    SCASUM = 0.0
    STEMP = 0.0
    IF (N.LE.0 .OR. INCX.LE.0) RETURN
    IF (INCX.EQ.1) THEN
       DO I = 1,N
          STEMP = STEMP + ABS(REAL(CX(I))) + ABS(AIMAG(CX(I)))
       END DO
    ELSE
       NINCX = N*INCX
       DO I = 1,NINCX,INCX
          STEMP = STEMP + ABS(REAL(CX(I))) + ABS(AIMAG(CX(I)))
       END DO
    END IF
    SCASUM = STEMP
  END FUNCTION SCASUM
END MODULE SCASUM_MOD

PROGRAM test_scasum
  USE SCASUM_MOD
  IMPLICIT NONE

  REAL :: result
  COMPLEX, DIMENSION(5) :: cx
  INTEGER :: n, incx

  ! Initialize the test data
  cx(1) = CMPLX(1.0, 2.0)
  cx(2) = CMPLX(3.0, -4.0)
  cx(3) = CMPLX(-5.0, 6.0)
  cx(4) = CMPLX(-7.0, -8.0)
  cx(5) = CMPLX(9.0, 10.0)
  n = 5
  incx = 1

  ! Call the function
  result = SCASUM(n, cx, incx)
  PRINT *, 'Result for SCASUM with incx=1: ', result
  IF (result /= 55.0) THEN
     PRINT *, "Test with incx=1 failed"
  ELSE
     PRINT *, "Test with incx=1 passed"
  END IF

  ! Test with different increment
  incx = 2
  result = SCASUM(3, cx, incx)
  PRINT *, 'Result for SCASUM with incx=2: ', result
  IF (result /= 33.0) THEN
     PRINT *, "Test with incx=2 failed"
  ELSE
     PRINT *, "Test with incx=2 passed"
  END IF

  PRINT *, "All tests completed."

END PROGRAM test_scasum