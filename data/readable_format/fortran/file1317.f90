PROGRAM ppm_test
    IMPLICIT NONE
    INTEGER, PARAMETER :: ppm_param_alloc_fit = 1
    INTEGER, PARAMETER :: ppm_param_alloc_fit_preserve = 2
    INTEGER, PARAMETER :: ppm_param_alloc_grow = 3
    INTEGER, PARAMETER :: ppm_param_alloc_grow_preserve = 4
    INTEGER, PARAMETER :: ppm_param_dealloc = 5
    INTEGER, PARAMETER :: ppm_error_error = -1
    INTEGER, PARAMETER :: ppm_err_argument = 1
    INTEGER, DIMENSION(2) :: ldl = [1, 2]
    INTEGER :: info
    CHARACTER(LEN=100) :: caller

    caller = "TestCaller"
    CALL ppm_alloc_argcheck(caller, ldl, ppm_param_alloc_fit, 2, info)
    IF (info == 0) THEN
        PRINT *, "Test 1 Passed"
    ELSE
        PRINT *, "Test 1 Failed"
    END IF

    CALL ppm_alloc_argcheck(caller, ldl, -1, 2, info) ! Invalid iopt
    IF (info /= 0) THEN
        PRINT *, "Test 2 Passed"
    ELSE
        PRINT *, "Test 2 Failed"
    END IF

CONTAINS

    SUBROUTINE ppm_alloc_argcheck(caller, ldl, iopt, dimension, info)
        CHARACTER(LEN=*)               , INTENT(IN)   :: caller
        INTEGER, DIMENSION(:)          , INTENT(IN)   :: ldl
        INTEGER                        , INTENT(IN)   :: iopt
        INTEGER                        , INTENT(IN)   :: dimension
        INTEGER                        , INTENT(OUT)  :: info
        INTEGER               :: i
        info = 0
        IF (iopt /= ppm_param_alloc_fit           .AND. &
            iopt /= ppm_param_alloc_fit_preserve  .AND. &
            iopt /= ppm_param_alloc_grow          .AND. &
            iopt /= ppm_param_alloc_grow_preserve .AND. &
            iopt /= ppm_param_dealloc) THEN
            CALL ppm_error(ppm_err_argument, caller, 'unknown iopt', 1, info)
            RETURN
        ENDIF
        DO i = 1, dimension
            IF (ldl(i) < 0) THEN
                CALL ppm_error(ppm_err_argument, caller, 'ldl() must be >= 0', 2, info)
                RETURN
            ENDIF
        ENDDO
    END SUBROUTINE ppm_alloc_argcheck

    SUBROUTINE ppm_error(err_code, caller, message, line, info)
        INTEGER, INTENT(IN) :: err_code
        CHARACTER(LEN=*), INTENT(IN) :: caller, message
        INTEGER, INTENT(IN) :: line
        INTEGER, INTENT(OUT) :: info
        PRINT *, "Error in ", caller, ": ", message, " at line ", line
        info = ppm_error_error
    END SUBROUTINE ppm_error

END PROGRAM ppm_test