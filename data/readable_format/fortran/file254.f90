PROGRAM TestCHR_NTH
      IMPLICIT NONE
      INTEGER :: i
      CHARACTER(2) :: result

! Declare an interface to the CHR_NTH function
      INTERFACE
          CHARACTER(2) FUNCTION CHR_NTH(IVALUE)
              INTEGER, INTENT(IN) :: IVALUE
          END FUNCTION CHR_NTH
      END INTERFACE

      DO i = 1, 24
         result = CHR_NTH(i)
         PRINT *, 'Number: ', i, ' Suffix: ', result
      ENDDO
END PROGRAM TestCHR_NTH

CHARACTER(2) FUNCTION CHR_NTH(IVALUE)
      IMPLICIT NONE
      INTEGER, INTENT(IN) :: IVALUE
      INTEGER :: TENS
      INTEGER :: UNITS
      CHARACTER(2), DIMENSION(0:3) :: TABLE = (/ 'th', 'st', 'nd', 'rd' /)
      TENS = MOD(ABS(IVALUE), 100)
      UNITS = MOD(TENS, 10)
      TENS = TENS - UNITS
      IF ((TENS .EQ. 10) .OR. (UNITS .GT. 3)) THEN
         CHR_NTH = 'th'
      ELSE
         CHR_NTH = TABLE(UNITS)
      END IF
END FUNCTION CHR_NTH