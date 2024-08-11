PROGRAM test_inirea
  IMPLICIT NONE
  INTEGER, PARAMETER :: len = 5
  REAL :: rfrom = 2.0
  REAL :: rto(len)
  INTEGER :: i
  
  CALL INIREA(len, rfrom, rto)
  
  PRINT *, "Testing INIREA"
  DO i = 1, len
     PRINT *, "rto(", i, ") = ", rto(i)
     IF (rto(i) .NE. rfrom) THEN
         PRINT *, "Test failed."
         STOP
     END IF
  END DO
  PRINT *, "All tests passed."
END PROGRAM test_inirea

SUBROUTINE INIREA (LEN, RFROM, RTO)
  INTEGER LEN
  REAL RFROM
  REAL RTO(LEN)
  
  INTEGER I
  DO I = 1, LEN
     RTO(I) = RFROM
  END DO
END SUBROUTINE INIREA