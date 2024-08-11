PROGRAM testXLAENV
  IMPLICIT NONE
  INTEGER :: IPARMS(100)
  COMMON /CLAENV/ IPARMS
  INTEGER :: value1, value2, value9

  ! Test calls
  CALL XLAENV(1, 10)
  CALL XLAENV(2, 20)
  CALL XLAENV(9, 90)  ! This should not affect IPARMS since ISPEC is out of the 1-8 range.

  ! Check results
  value1 = IPARMS(1)
  value2 = IPARMS(2)
  value9 = IPARMS(9)

  IF (value1 == 10 .AND. value2 == 20 .AND. value9 == 0) THEN
      PRINT *, 'Test passed.'
  ELSE
      PRINT *, 'Test failed.'
  END IF
END PROGRAM testXLAENV

SUBROUTINE XLAENV(ISPEC, NVALUE)
  INTEGER, INTENT(IN) :: ISPEC, NVALUE
  INTEGER :: IPARMS(100)
  COMMON /CLAENV/ IPARMS

  IF (ISPEC >= 1 .AND. ISPEC <= 8) THEN
     IPARMS(ISPEC) = NVALUE
  END IF
END SUBROUTINE XLAENV