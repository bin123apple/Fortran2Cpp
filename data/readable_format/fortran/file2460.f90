MODULE COM_VAR
    IMPLICIT NONE
    REAL :: RHO = 1.225
    REAL :: G = 9.81
    REAL :: Depth = 100.0
    REAL :: XEFF = 1.0, YEFF = 2.0, ZEFF = 3.0    
    CHARACTER(LEN=80) :: MESHFILE = 'mesh.dat'
    INTEGER :: LFILE = 10, NP = 1000, NFA = 2000
    INTEGER :: IMX = 10, IXX = 20, NSYMY = 30
    REAL :: ZER = 0.0
    INTEGER :: Indiq_solver = 1
    INTEGER :: Sav_potential = 1
    ! Add more variables as needed
END MODULE COM_VAR

PROGRAM Test_COM_VAR
    USE COM_VAR
    IMPLICIT NONE

    ! Initialize or use variables
    RHO = 1.225
    G = 9.81
    Depth = 100.0
    XEFF = 1.0
    YEFF = 2.0
    ZEFF = 3.0

    PRINT *, 'RHO:', RHO
    PRINT *, 'G:', G
    PRINT *, 'Depth:', Depth
    PRINT *, 'XEFF:', XEFF, 'YEFF:', YEFF, 'ZEFF:', ZEFF

    ! Add more code as needed
END PROGRAM Test_COM_VAR