MODULE InterpData
    INTEGER, PARAMETER :: NF = 55
    REAL, DIMENSION(7, NF) :: CIA = 1.0
    REAL, DIMENSION(NF) :: CPR
    REAL, DIMENSION(7) :: tempgrid = (/100.0, 150.0, 200.0, 250.0, 300.0, 350.0, 400.0/)
CONTAINS
    SUBROUTINE interpco2cia(Temp)
        REAL :: Temp, tempr, Tnum, Tden, FX, CIAMS1L, CIAMSL, CPRL
        INTEGER :: M, MS, MS1, IK

        tempr = Temp
        MS = 8
        DO M = 1, 7
            IF (tempr < tempgrid(M)) THEN
                MS = M
                EXIT
            END IF
        END DO

        IF (MS <= 1) THEN
            MS1 = MS
            FX = 1.0
        ELSEIF (MS >= 8) THEN
            MS = MS - 1
            MS1 = MS
            FX = 1.0
        ELSE
            MS1 = MS - 1
            Tnum = tempr - tempgrid(MS1)
            Tden = tempgrid(MS) - tempgrid(MS1)
            FX = Tnum / Tden
        END IF

        DO IK = 1, NF
            CIAMS1L = LOG(CIA(MS1, IK))
            CIAMSL = LOG(CIA(MS, IK))
            CPRL = CIAMS1L + FX * (CIAMSL - CIAMS1L)
            CPR(IK) = EXP(CPRL)
        END DO
    END SUBROUTINE interpco2cia
END MODULE InterpData

PROGRAM TestInterpCO2CIA
    USE InterpData
    IMPLICIT NONE
    INTEGER :: i, IK
    REAL :: TempTest(3) = (/100.0, 250.0, 400.0/)

    DO i = 1, SIZE(TempTest)
        CALL interpco2cia(TempTest(i))
        PRINT *, 'Temperature =', TempTest(i)
        DO IK = 1, 5
            PRINT *, 'CPR(', IK, ') = ', CPR(IK)
        END DO
        PRINT *, '----------'
    END DO
END PROGRAM TestInterpCO2CIA