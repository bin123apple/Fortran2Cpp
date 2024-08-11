! CSINTRSC.f90
SUBROUTINE CSINTRSC (P1, P2, CN, P, IER)
  INTEGER IER
  DOUBLE PRECISION P1(3), P2(3), CN(3), P(3)
  INTEGER I
  DOUBLE PRECISION D1, D2, PP(3), PPN, T

  D1 = CN(1) * P1(1) + CN(2) * P1(2) + CN(3) * P1(3)
  D2 = CN(1) * P2(1) + CN(2) * P2(2) + CN(3) * P2(3)

  IF (D1 .EQ. D2) THEN
      IER = 1
      P(1) = 0.0D0
      P(2) = 0.0D0
      P(3) = 0.0D0
      RETURN
  ENDIF

  T = D1 / (D1 - D2)
  PPN = 0D0
  DO I = 1, 3
     PP(I) = P1(I) + T * (P2(I) - P1(I))
     PPN = PPN + PP(I) * PP(I)
  END DO

  IF (PPN .EQ. 0D0) THEN
      IER = 2
      RETURN
  ENDIF
  PPN = SQRT(PPN)

  DO I = 1, 3
     P(I) = PP(I) / PPN
  END DO
  IER = 0
END SUBROUTINE

PROGRAM test_CSINTRSC
  IMPLICIT NONE
  DOUBLE PRECISION P1(3), P2(3), CN(3), P(3)
  INTEGER IER, I

  P1 = (/1.D0, 0.D0, 0.D0/)
  P2 = (/0.D0, 1.D0, 0.D0/)
  CN = (/0.D0, 0.D0, 1.D0/)

  CALL CSINTRSC(P1, P2, CN, P, IER)

  PRINT *, 'IER:', IER
  PRINT *, 'P:'
  DO I=1,3
    PRINT *, P(I)
  END DO
END PROGRAM test_CSINTRSC

! Compile with: gfortran -o test_CSINTRSC CSINTRSC.f90
! Run with: ./test_CSINTRSC