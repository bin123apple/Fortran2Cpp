PROGRAM TestLXRST
  IMPLICIT NONE
  CHARACTER*504 ILINE
  INTEGER JLINE, LXINIT
  COMMON /LXCOM1/ILINE
  COMMON /LXCOM2/JLINE,LXINIT

  CALL LXRST

  PRINT *, 'LXINIT:', LXINIT
  PRINT *, 'JLINE:', JLINE
  PRINT *, 'ILINE(504):', ILINE(504:504)

END PROGRAM TestLXRST

SUBROUTINE LXRST
  IMPLICIT INTEGER (A-Z)
  CHARACTER*504 ILINE
  COMMON /LXCOM1/ILINE
  COMMON /LXCOM2/JLINE,LXINIT

  LXINIT = 12345
  JLINE = 504
  ILINE(JLINE:JLINE) = CHAR(0)
  RETURN

END SUBROUTINE LXRST