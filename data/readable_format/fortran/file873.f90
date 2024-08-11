MODULE MOD_DG_Vars
    IMPLICIT NONE
    PUBLIC
    REAL, ALLOCATABLE :: D(:,:)                 
    REAL, ALLOCATABLE :: D_T(:,:)               
    REAL, ALLOCATABLE :: D_Hat(:,:)             
    REAL, ALLOCATABLE :: D_Hat_T(:,:)           
    REAL, ALLOCATABLE :: L_HatMinus(:)          
    REAL, ALLOCATABLE :: L_HatPlus(:)           
    REAL, ALLOCATABLE :: DVolSurf(:,:)          
    REAL, ALLOCATABLE, TARGET :: U(:,:,:,:,:)
    REAL, ALLOCATABLE :: Ut(:,:,:,:,:)
    INTEGER :: nTotalU                
    INTEGER :: nDOFFace               
    INTEGER :: nDOFElem               
    REAL, ALLOCATABLE :: U_master(:,:,:,:)      
    REAL, ALLOCATABLE :: U_slave(:,:,:,:)       
    REAL, ALLOCATABLE :: Flux_master(:,:,:,:)   
    REAL, ALLOCATABLE :: Flux_slave(:,:,:,:)   
    REAL, ALLOCATABLE :: UPrim(:,:,:,:,:)
    REAL, ALLOCATABLE :: UPrim_master(:,:,:,:)  
    REAL, ALLOCATABLE :: UPrim_slave(:,:,:,:)   
    INTEGER :: SplitDG                
    REAL, ALLOCATABLE :: UPrim_Boundary(:,:,:,:)
    LOGICAL :: DGInitIsDone = .FALSE.
END MODULE MOD_DG_Vars

PROGRAM TestMOD_DG_Vars
    USE MOD_DG_Vars
    IMPLICIT NONE

    ! Allocate some arrays with arbitrary sizes for testing
    ALLOCATE(D(10,10))
    ALLOCATE(D_T(10,10))
    ALLOCATE(D_Hat(10,10))
    ALLOCATE(D_Hat_T(10,10))
    ALLOCATE(L_HatMinus(10))
    ALLOCATE(L_HatPlus(10))
    ALLOCATE(U(5,5,5,5,2))
    ALLOCATE(Ut(5,5,5,5,2))
    ALLOCATE(U_master(5,5,5,5))
    ALLOCATE(U_slave(5,5,5,5))
    ALLOCATE(Flux_master(5,5,5,5))
    ALLOCATE(Flux_slave(5,5,5,5))
    ALLOCATE(UPrim(5,5,5,5,2))
    ALLOCATE(UPrim_master(5,5,5,5))
    ALLOCATE(UPrim_slave(5,5,5,5))
    ALLOCATE(UPrim_Boundary(3,3,3,2))

    ! Initialize some values
    D = 1.0
    U = 2.0
    UPrim_Boundary = 3.0

    ! Simple checks to verify allocation and initialization
    IF (ALL(D == 1.0) .AND. ALL(U == 2.0) .AND. ALL(UPrim_Boundary == 3.0)) THEN
        PRINT *, "Fortran Test Passed"
    ELSE
        PRINT *, "Fortran Test Failed"
    END IF

    ! Clean up
    DEALLOCATE(D)
    DEALLOCATE(D_T)
    DEALLOCATE(D_Hat)
    DEALLOCATE(D_Hat_T)
    DEALLOCATE(L_HatMinus)
    DEALLOCATE(L_HatPlus)
    DEALLOCATE(U)
    DEALLOCATE(Ut)
    DEALLOCATE(U_master)
    DEALLOCATE(U_slave)
    DEALLOCATE(Flux_master)
    DEALLOCATE(Flux_slave)
    DEALLOCATE(UPrim)
    DEALLOCATE(UPrim_master)
    DEALLOCATE(UPrim_slave)
    DEALLOCATE(UPrim_Boundary)

END PROGRAM TestMOD_DG_Vars