PROGRAM TestSla__IDCHI
  IMPLICIT NONE

  CHARACTER(LEN=20) :: STRING
  INTEGER :: NPTR, NVEC
  DOUBLE PRECISION :: DIGIT

  ! Test 1
  STRING = '1234'
  NPTR = 1
  CALL sla__IDCHI(STRING, NPTR, NVEC, DIGIT)
  PRINT *, 'Test 1: ', NVEC, DIGIT, NPTR

  ! Test 2
  STRING = '9+,- '
  NPTR = 2
  CALL sla__IDCHI(STRING, NPTR, NVEC, DIGIT)
  PRINT *, 'Test 2: ', NVEC, DIGIT, NPTR

  ! Test 3
  STRING = CHAR(9) // 'Tab test'
  NPTR = 1
  CALL sla__IDCHI(STRING, NPTR, NVEC, DIGIT)
  PRINT *, 'Test 3: ', NVEC, DIGIT, NPTR

CONTAINS

  SUBROUTINE sla__IDCHI (STRING, NPTR, NVEC, DIGIT)
    IMPLICIT NONE
    CHARACTER(LEN=*), INTENT(INOUT) :: STRING
    INTEGER, INTENT(INOUT) :: NPTR, NVEC
    DOUBLE PRECISION, INTENT(OUT) :: DIGIT

    CHARACTER :: K
    INTEGER :: NCHAR

    INTEGER, PARAMETER :: NCREC=14
    CHARACTER :: KCTAB(NCREC) = (/ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', &
                                  ' ', '+', '-', ',' /)
    INTEGER :: KVTAB(NCREC) = (/ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 3, 4, 5 /)

    IF (NPTR.LT.1.OR.NPTR.GT.LEN(STRING)) THEN
       NVEC=7
    ELSE
       K=STRING(NPTR:NPTR)
       DO NCHAR=1,NCREC
          IF (K.EQ.KCTAB(NCHAR)) THEN
             NVEC=KVTAB(NCHAR)
             DIGIT=DBLE(NCHAR-1)
             GO TO 2300
          END IF
       END DO
       IF (K.EQ.CHAR(9)) THEN
          NVEC=2
       ELSE
          NVEC=6
       END IF
2300   CONTINUE
       NPTR=NPTR+1
    END IF
  END SUBROUTINE sla__IDCHI

END PROGRAM TestSla__IDCHI