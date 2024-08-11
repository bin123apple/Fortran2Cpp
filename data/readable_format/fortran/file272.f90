PROGRAM test_sqzlgv
  IMPLICIT NONE
  INTEGER, PARAMETER :: nptims = 5
  INTEGER :: iptims(nptims) = (/1, 2, 3, 4, 5/)
  LOGICAL :: whotim(nptims) = (/ .TRUE., .FALSE., .TRUE., .FALSE., .TRUE. /)
  REAL :: valin(nptims) = (/1.0, 2.0, 3.0, 4.0, 5.0/)
  REAL :: valout(nptims)
  INTEGER :: nptout, i

  CALL SQZLGV(nptims, iptims, whotim, valin, nptout, valout)

  PRINT *, "Filtered values:"
  DO i = 1, nptout
     PRINT *, valout(i)
  END DO
  
  ! Add checks to validate the output
  IF (nptout /= 3) THEN
     PRINT *, "Test failed: Incorrect number of output values."
  ELSE
     IF (ALL(valout(1:nptout) == (/1.0, 3.0, 5.0/))) THEN
        PRINT *, "Test passed."
     ELSE
        PRINT *, "Test failed: Output values are incorrect."
     END IF
  END IF

END PROGRAM test_sqzlgv

SUBROUTINE SQZLGV(NPTIMS, IPTIMS, WHOTIM, VALIN, NPTOUT, VALOUT)
  INTEGER, INTENT(IN) :: NPTIMS
  INTEGER, INTENT(IN) :: IPTIMS(*)
  LOGICAL, INTENT(IN) :: WHOTIM(*)
  REAL, INTENT(IN) :: VALIN(*)
  REAL, INTENT(OUT) :: VALOUT(*)
  INTEGER, INTENT(OUT) :: NPTOUT

  INTEGER :: I
  
  NPTOUT = 0
  DO I = 1, NPTIMS
     IF (WHOTIM(IPTIMS(I))) THEN
        NPTOUT = NPTOUT + 1
        VALOUT(NPTOUT) = VALIN(I)
     END IF
  END DO

END SUBROUTINE SQZLGV