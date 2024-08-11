MODULE NWTC_Base
    USE, INTRINSIC :: ISO_C_Binding
    IMPLICIT NONE

    INTEGER, PARAMETER :: BITS_IN_ADDR = C_INTPTR_T*8
    INTEGER, PARAMETER :: ErrMsgLen = 1024
    INTEGER, PARAMETER :: ChanLen = 10
    INTEGER, PARAMETER :: NWTC_Verbose = 10
    INTEGER, PARAMETER :: NWTC_VerboseLevel = 5
    INTEGER, PARAMETER :: ErrID_None = 0
    INTEGER, PARAMETER :: ErrID_Info = 1
    INTEGER, PARAMETER :: ErrID_Warn = 2
    INTEGER, PARAMETER :: ErrID_Severe = 3
    INTEGER, PARAMETER :: ErrID_Fatal = 4
    INTEGER :: AbortErrLev = ErrID_Fatal
    INTEGER, PARAMETER :: NWTC_MAX_DLL_PROC = 3

    TYPE DLL_Type
        INTEGER(C_INTPTR_T) :: FileAddr
        TYPE(C_PTR) :: FileAddrX = C_NULL_PTR
        TYPE(C_FUNPTR) :: ProcAddr(NWTC_MAX_DLL_PROC) = C_NULL_FUNPTR
        CHARACTER(1024) :: FileName = ""
        CHARACTER(1024) :: ProcName(NWTC_MAX_DLL_PROC) = ""
    END TYPE DLL_Type
END MODULE NWTC_Base

PROGRAM TestNWTC_Base
    USE NWTC_Base
    IMPLICIT NONE

    TYPE(DLL_Type) :: dll
    INTEGER :: i

    PRINT *, "Testing NWTC_Base Module..."

    IF (.NOT. C_ASSOCIATED(dll%FileAddrX)) THEN
        PRINT *, "PASS: FileAddrX is NULL."
    ELSE
        PRINT *, "FAIL: FileAddrX is not NULL."
    END IF

    DO i = 1, NWTC_MAX_DLL_PROC
        IF (.NOT. C_ASSOCIATED(dll%ProcAddr(i))) THEN
            PRINT *, "PASS: ProcAddr(", i, ") is NULL."
        ELSE
            PRINT *, "FAIL: ProcAddr(", i, ") is not NULL."
        END IF
    END DO

    IF (TRIM(dll%FileName) == "") THEN
        PRINT *, "PASS: FileName is empty."
    ELSE
        PRINT *, "FAIL: FileName is not empty."
    END IF

    DO i = 1, NWTC_MAX_DLL_PROC
        IF (TRIM(dll%ProcName(i)) == "") THEN
            PRINT *, "PASS: ProcName(", i, ") is empty."
        ELSE
            PRINT *, "FAIL: ProcName(", i, ") is not empty."
        END IF
    END DO
END PROGRAM TestNWTC_Base