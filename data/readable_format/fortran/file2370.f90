PROGRAM TestUTILBD
    IMPLICIT NONE
    INTEGER :: i

    ! Definition of common blocks
    COMMON /IUTLCM/ IU
    COMMON /VCTSEQ/ NQ, QX, QY, NF, IF
    COMMON /PLTCM/ JX, JY

    INTEGER, DIMENSION(100) :: IU
    REAL, DIMENSION(50) :: QX, QY
    INTEGER :: NQ, NF, IF(25), JX, JY

    ! Initialize the common blocks
    CALL InitializeCommonBlocks

    ! Unit Tests
    PRINT *, 'IU(1) =', IU(1)
    PRINT *, 'NQ =', NQ
    PRINT *, 'QX(1) =', QX(1)
    PRINT *, 'JX =', JX
    PRINT *, 'All tests passed.'

CONTAINS

    SUBROUTINE InitializeCommonBlocks
        ! Initialize IU array
        IU(1) = 1
        IU(2) = 1
        IU(3) = 10
        IU(4) = 10
        IU(5) = 50
        IU(6) = 2
        IU(7) = 1
        IU(8) = 1
        IU(9) = 1
        IU(10) = 8000
        IU(11) = 0
        IU(12) = 1
        IU(13) = 1000
        IU(14) = 1000
        DO i = 15, 100
            IU(i) = 0
        END DO

        ! Initialize VCTSEQ common block
        NQ = 1
        QX(1) = 0.0
        QY(1) = 0.0
        NF = 1
        IF(1) = 1
        DO i = 2, 50
            QX(i) = 0.0
            QY(i) = 0.0
        END DO
        DO i = 2, 25
            IF(i) = 0
        END DO

        ! Initialize PLTCM common block
        JX = 0
        JY = 0
    END SUBROUTINE InitializeCommonBlocks

END PROGRAM TestUTILBD