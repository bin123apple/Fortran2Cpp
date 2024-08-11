SUBROUTINE CNTNZU (N, IA, JA, NZSUT)
      INTEGER N, IA(*), JA(*), NZSUT
      INTEGER II, JJ, J, JMIN, JMAX, K, KMIN, KMAX, NUM
      NUM = 0
      DO 50 II = 1,N
        JMIN = IA(II)
        JMAX = IA(II+1) - 1
        IF (JMIN .GT. JMAX) GO TO 50
        DO 40 J = JMIN,JMAX
          JJ = JA(J)
          IF (JJ .EQ. II) GO TO 40
          KMIN = IA(JJ)
          KMAX = IA(JJ+1) - 1
          DO 30 K = KMIN,KMAX
            IF (JA(K) .EQ. II) THEN
              GO TO 40
            END IF
 30       CONTINUE
          NUM = NUM + 1
 40       CONTINUE
 50     CONTINUE
      NZSUT = NUM
      RETURN
      END

PROGRAM TestCNTNZU
  INTEGER N, IA(6), JA(10), NZSUT
  N = 5
  IA = (/1, 2, 4, 6, 8, 10/)
  JA = (/1, 3, 2, 5, 4, 1, 3, 5, 2, 4/)
  CALL CNTNZU(N, IA, JA, NZSUT)
  PRINT *, 'NZSUT:', NZSUT
END PROGRAM TestCNTNZU