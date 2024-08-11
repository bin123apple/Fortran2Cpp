MODULE MOD_Filter_Vars
    IMPLICIT NONE
    PUBLIC
    SAVE

    INTEGER                :: NFilter               
    INTEGER                :: FilterType            
    REAL                   :: HestFilterParam(3)    
    REAL, ALLOCATABLE      :: FilterMat(:,:)        
    LOGICAL                :: FilterInitIsDone = .FALSE. 

    ! Variables that would be conditionally compiled
    REAL, ALLOCATABLE       :: lim(:)                
    REAL, ALLOCATABLE       :: eRatio(:)             
    REAL, ALLOCATABLE       :: r(:)                  
    REAL, ALLOCATABLE       :: ekin_avg_old(:)       
    REAL, ALLOCATABLE       :: ekin_fluc_avg_old(:)  
    REAL, ALLOCATABLE       :: IntegrationWeight(:,:,:,:,:)  
    REAL                   :: normMod               
    REAL                   :: LAF_alpha             

    LOGICAL                :: DoPPLimiter            
    INTEGER                :: iPPRefState            
    REAL                   :: PPEpsFac               
    REAL                   :: PPepsDens              
    REAL                   :: PPepsPres              
    INTEGER, ALLOCATABLE   :: PP_Elems(:)            
    INTEGER, ALLOCATABLE   :: PP_Elems_counter(:)    
    INTEGER                :: PP_Switch_counter      
    REAL, ALLOCATABLE      :: PP_Elems_Amount(:)     
END MODULE MOD_Filter_Vars

PROGRAM Test_MOD_Filter_Vars
    USE MOD_Filter_Vars
    IMPLICIT NONE

    PRINT *, "Testing module MOD_Filter_Vars"

    ! Test variable initialization
    IF (.NOT. FilterInitIsDone) THEN
        PRINT *, "FilterInitIsDone is FALSE as expected."
    ELSE
        PRINT *, "ERROR: FilterInitIsDone is not FALSE."
    END IF

    ! Here you would manually adjust the code to test conditionally compiled sections
    ! For example:
    PRINT *, "Manually testing variables that would be conditionally compiled."
    normMod = 5.0
    PRINT *, "normMod assigned as:", normMod
    ! Add more tests as needed

END PROGRAM Test_MOD_Filter_Vars