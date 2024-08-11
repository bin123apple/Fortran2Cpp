PROGRAM TestCombak
    IMPLICIT NONE
    INTEGER, PARAMETER :: NM = 5, M = 2, LOW = 1, IGH = 5
    REAL :: AR(NM, NM), AI(NM, NM), ZR(NM, M), ZI(NM, M)
    INTEGER :: INT(NM)
    INTEGER :: I, J

    ! Initialize matrices AR, AI, ZR, ZI, and vector INT with test values
    ! For simplicity, all initialized to 1 here; replace with actual test values
    AR = 1.0
    AI = 1.0
    ZR = 1.0
    ZI = 1.0
    INT = (/1, 2, 3, 4, 5/)

    ! Call COMBAK subroutine
    CALL COMBAK(NM, LOW, IGH, AR, AI, INT, M, ZR, ZI)

    ! Output the results for manual verification or add checks for expected values
    PRINT *, 'ZR:'
    DO I = 1, NM
        WRITE(*, '(5F10.5)') ZR(I, :)
    END DO

    PRINT *, 'ZI:'
    DO I = 1, NM
        WRITE(*, '(5F10.5)') ZI(I, :)
    END DO

END PROGRAM TestCombak

SUBROUTINE COMBAK(NM, LOW, IGH, AR, AI, INT, M, ZR, ZI)
    INTEGER I,J,M,LA,MM,MP,NM,IGH,KP1,LOW,MP1
    REAL AR(NM,*),AI(NM,*),ZR(NM,*),ZI(NM,*)
    REAL XR,XI
    INTEGER INT(*)
    IF (M .EQ. 0) RETURN
    LA = IGH - 1
    KP1 = LOW + 1
    IF (LA .LT. KP1) RETURN
    DO 140 MM = KP1, LA
       MP = LOW + IGH - MM
       MP1 = MP + 1
       DO 110 I = MP1, IGH
          XR = AR(I,MP-1)
          XI = AI(I,MP-1)
          IF (XR .EQ. 0.0E0 .AND. XI .EQ. 0.0E0) GO TO 110
          DO 100 J = 1, M
             ZR(I,J) = ZR(I,J) + XR * ZR(MP,J) - XI * ZI(MP,J)
             ZI(I,J) = ZI(I,J) + XR * ZI(MP,J) + XI * ZR(MP,J)
 100       CONTINUE
 110    CONTINUE
          I = INT(MP)
          IF (I .EQ. MP) GO TO 140
          DO 130 J = 1, M
             XR = ZR(I,J)
             ZR(I,J) = ZR(MP,J)
             ZR(MP,J) = XR
             XI = ZI(I,J)
             ZI(I,J) = ZI(MP,J)
             ZI(MP,J) = XI
 130       CONTINUE
 140    CONTINUE
    RETURN
END SUBROUTINE COMBAK