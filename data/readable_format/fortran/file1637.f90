PROGRAM TestSLAMRG
  IMPLICIT NONE
  INTEGER, PARAMETER :: n1 = 5, n2 = 5
  INTEGER :: i
  INTEGER :: INDEX(n1+n2)
  REAL :: A(n1+n2) = [1.0, 3.0, 5.0, 7.0, 9.0, 2.0, 4.0, 6.0, 8.0, 10.0]

  CALL SLAMRG(n1, n2, A, 1, 1, INDEX)

  PRINT *, 'Fortran Test Output: '
  DO i = 1, n1+n2
      PRINT *, INDEX(i)
  END DO
END PROGRAM TestSLAMRG

SUBROUTINE SLAMRG(N1, N2, A, STRD1, STRD2, INDEX)
  INTEGER, INTENT(IN) :: N1, N2, STRD1, STRD2
  INTEGER, INTENT(OUT) :: INDEX(*)
  REAL, INTENT(IN) :: A(*)
  INTEGER :: IND1, IND2, N1SV, N2SV, I

  N1SV = N1
  N2SV = N2
  IF(STRD1 > 0) THEN
     IND1 = 1
  ELSE
     IND1 = N1
  ENDIF
  IF(STRD2 > 0) THEN
     IND2 = 1 + N1
  ELSE
     IND2 = N1 + N2
  ENDIF
  I = 1

  DO WHILE(N1SV > 0 .AND. N2SV > 0)
     IF(A(IND1) <= A(IND2)) THEN
        INDEX(I) = IND1
        I = I + 1
        IND1 = IND1 + STRD1
        N1SV = N1SV - 1
     ELSE
        INDEX(I) = IND2
        I = I + 1
        IND2 = IND2 + STRD2
        N2SV = N2SV - 1
     ENDIF
  END DO

  IF(N1SV == 0) THEN
     DO WHILE(N2SV > 0)
        INDEX(I) = IND2
        I = I + 1
        IND2 = IND2 + STRD2
        N2SV = N2SV - 1
     END DO
  ELSE
     DO WHILE(N1SV > 0)
        INDEX(I) = IND1
        I = I + 1
        IND1 = IND1 + STRD1
        N1SV = N1SV - 1
     END DO
  ENDIF
END SUBROUTINE SLAMRG