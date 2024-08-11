PROGRAM TestCharln
  IMPLICIT NONE
  
  CHARACTER(LEN=20) :: text
  INTEGER :: klen
  
  ! Test case 1: String with trailing spaces
  text = 'Hello, World!    '
  CALL CHARLN(text, klen)
  PRINT *, 'Test 1:', 'Expected length: 13, Actual:', klen, 'Text: "', TRIM(text), '"'
  
  ! Test case 2: String without trailing spaces
  text = 'Fortran'
  CALL CHARLN(text, klen)
  PRINT *, 'Test 2:', 'Expected length: 7, Actual:', klen, 'Text: "', TRIM(text), '"'
  
  ! Test case 3: Empty string
  text = ''
  CALL CHARLN(text, klen)
  PRINT *, 'Test 3:', 'Expected length: 0, Actual:', klen, 'Text: "', TRIM(text), '"'

END PROGRAM TestCharln

SUBROUTINE CHARLN(TEXT,KLEN)
  CHARACTER*(*) TEXT
  INTEGER KLEN, K
  KLEN = LEN_TRIM(TEXT)
  K = 1
  DO WHILE (K.EQ.1.AND.KLEN.GT.0)
     IF (TEXT(KLEN:KLEN).EQ.' ') THEN
        KLEN = KLEN - 1
     ELSE
        K = 0
     END IF
  END DO
END SUBROUTINE CHARLN