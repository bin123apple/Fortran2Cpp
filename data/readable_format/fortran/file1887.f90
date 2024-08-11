! Define the DLAMRG subroutine
SUBROUTINE DLAMRG( N1, N2, A, DTRD1, DTRD2, INDEX )
  INTEGER            DTRD1, DTRD2, N1, N2
  INTEGER            INDEX( * )
  DOUBLE PRECISION   A( * )
  INTEGER            I, IND1, IND2, N1SV, N2SV

  N1SV = N1
  N2SV = N2
  IF( DTRD1.GT.0 ) THEN
     IND1 = 1
  ELSE
     IND1 = N1
  END IF
  IF( DTRD2.GT.0 ) THEN
     IND2 = 1 + N1
  ELSE
     IND2 = N1 + N2
  END IF
  I = 1
  DO WHILE (N1SV.GT.0 .AND. N2SV.GT.0)
     IF( A( IND1 ).LE.A( IND2 ) ) THEN
        INDEX( I ) = IND1
        I = I + 1
        IND1 = IND1 + DTRD1
        N1SV = N1SV - 1
     ELSE
        INDEX( I ) = IND2
        I = I + 1
        IND2 = IND2 + DTRD2
        N2SV = N2SV - 1
     END IF
  END DO
  IF( N1SV.EQ.0 ) THEN
     DO I = I, I + N2SV - 1
        INDEX( I ) = IND2
        IND2 = IND2 + DTRD2
     END DO
  ELSE
     DO I = I, I + N1SV - 1
        INDEX( I ) = IND1
        IND1 = IND1 + DTRD1
     END DO
  END IF

  RETURN
END SUBROUTINE DLAMRG

! Test program to use DLAMRG
PROGRAM testDLAMRG
  IMPLICIT NONE
  INTEGER, PARAMETER :: n1=5, n2=5
  DOUBLE PRECISION, DIMENSION(n1+n2) :: A
  INTEGER, DIMENSION(n1+n2) :: INDEX
  INTEGER :: i

  ! Initialize arrays
  A = (/1.0, 6.0, 3.0, 7.0, 5.0, 2.0, 8.0, 4.0, 9.0, 10.0/)
  CALL DLAMRG(n1, n2, A, 1, 1, INDEX)

  PRINT *, 'INDEX:'
  DO i = 1, n1+n2
     PRINT *, INDEX(i)
  END DO
END PROGRAM testDLAMRG