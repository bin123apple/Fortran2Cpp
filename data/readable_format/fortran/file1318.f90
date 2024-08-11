PROGRAM testZMESS
    IMPLICIT NONE

    INTEGER, PARAMETER :: arrSize = 5
    INTEGER :: NUMESS, LESSEL, LESSDL
    INTEGER :: IDESS(arrSize), NEESS(arrSize), NEDSS(arrSize)
    INTEGER :: IXEESS(arrSize), IXEDSS(arrSize), LTEESS(arrSize)
    INTEGER :: LTSSS(arrSize), LTSNC(arrSize)
    REAL :: FAC(arrSize)
    LOGICAL :: USESDF
    INTEGER :: i

    ! Initialize input arrays and variables
    NUMESS = 2
    LESSEL = 0
    LESSDL = 0
    IDESS = (/1, 2, 0, 0, 0/)
    NEESS = (/2, 3, 0, 0, 0/)
    NEDSS = (/0, 0, 0, 0, 0/)
    IXEESS = (/1, 3, 0, 0, 0/)
    IXEDSS = (/1, 4, 0, 0, 0/)
    LTEESS = (/1, 2, 3, 0, 0/)
    LTSSS = (/4, 5, 6, 0, 0/)
    LTSNC = (/7, 8, 9, 0, 0/)
    FAC = (/1.0, 2.0, 3.0, 0.0, 0.0/)
    USESDF = .TRUE.

    CALL ZMESS(NUMESS, LESSEL, LESSDL, IDESS, NEESS, NEDSS, IXEESS, IXEDSS, LTEESS, LTSSS, LTSNC, FAC, USESDF)

    ! Output and check the results
    PRINT *, 'NUMESS:', NUMESS
    PRINT *, 'LESSEL:', LESSEL
    PRINT *, 'LESSDL:', LESSDL
    DO i = 1, NUMESS
        PRINT *, 'IDESS(', i, '):', IDESS(i)
        PRINT *, 'NEESS(', i, '):', NEESS(i)
        PRINT *, 'NEDSS(', i, '):', NEDSS(i)
        PRINT *, 'IXEESS(', i, '):', IXEESS(i)
        PRINT *, 'IXEDSS(', i, '):', IXEDSS(i)
    END DO

CONTAINS

    SUBROUTINE ZMESS(NUMESS, LESSEL, LESSDL, IDESS, NEESS, NEDSS, IXEESS, IXEDSS, LTEESS, LTSSS, LTSNC, FAC, USESDF)
        INTEGER, INTENT(INOUT) :: NUMESS, LESSEL, LESSDL
        INTEGER, INTENT(INOUT) :: IDESS(*), NEESS(*), NEDSS(*), IXEESS(*), IXEDSS(*), LTEESS(*), LTSSS(*), LTSNC(*)
        REAL, INTENT(INOUT) :: FAC(*)
        LOGICAL, INTENT(IN) :: USESDF
        INTEGER :: JESS, JNE, JDF, IDFE, IESS, N, NE, ICNT, nd1, IDFB, JNELST, JDFLST, nd

        IF (NUMESS .LE. 0) RETURN

        JESS = 0
        JNE = 0
        JDF = 0
        IDFE = 0
        DO IESS = 1, NUMESS
            JNELST = JNE
            JDFLST = JDF
            nd1 = IXEDSS(IESS)
            IDFB = nd1
            DO N = 1, NEESS(IESS)
                NE = N + IXEESS(IESS) - 1
                ICNT = LTSNC(NE)
                IDFE = IDFB + ICNT - 1
                IF (LTEESS(NE) .GT. 0) THEN
                    JNE = JNE + 1
                    LTEESS(JNE) = LTEESS(NE)
                    LTSSS(JNE)  = LTSSS(NE)
                    LTSNC(JNE)  = LTSNC(NE)
                    IF (USESDF) THEN
                        DO nd = IDFB, IDFE
                            JDF = JDF + 1
                            FAC(JDF) = FAC(nd)
                        END DO
                    END IF
                END IF
                IDFB = IDFE + 1
            END DO
            N = JNE - JNELST
            IF (N .GT. 0) THEN
                JESS = JESS + 1
                IDESS(JESS) = IDESS(IESS)
                NEESS(JESS) = N
                IXEESS(JESS) = JNELST + 1
                IF (USESDF) THEN
                    NEDSS(JESS) = JDF - JDFLST
                    IXEDSS(JESS) = JDFLST + 1
                END IF
            END IF
        END DO
        NUMESS = JESS
        LESSEL = JNE
        IF (USESDF) THEN
            IF (IDFE .NE. LESSDL) STOP 'ZMESS: Internal error'
            LESSDL = JDF
        END IF
    END SUBROUTINE ZMESS

END PROGRAM testZMESS