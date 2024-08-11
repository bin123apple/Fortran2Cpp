! Exactfunc_Vars_test.f90
MODULE MOD_Exactfunc_Vars
    IMPLICIT NONE
    REAL :: OmegaRef
END MODULE MOD_Exactfunc_Vars

PROGRAM test_OmegaRef
    USE MOD_Exactfunc_Vars
    IMPLICIT NONE

    ! Test setting and getting OmegaRef
    OmegaRef = 5.0
    WRITE(*,*) "Testing OmegaRef..."
    IF(OmegaRef == 5.0) THEN
        WRITE(*,*) "Test PASS: OmegaRef set and retrieved successfully."
    ELSE
        WRITE(*,*) "Test FAIL: OmegaRef value incorrect."
    END IF
END PROGRAM test_OmegaRef