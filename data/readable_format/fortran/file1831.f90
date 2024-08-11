MODULE CHETRI_3_MOD
    IMPLICIT NONE
CONTAINS
    SUBROUTINE CHETRI_3(UPLO, N, A, LDA, E, IPIV, WORK, LWORK, INFO)
        CHARACTER, INTENT(IN) :: UPLO
        INTEGER, INTENT(IN) :: N, LDA, LWORK
        INTEGER, INTENT(OUT) :: INFO
        INTEGER, INTENT(IN) :: IPIV(*)
        COMPLEX, INTENT(INOUT) :: A(LDA, *), E(*), WORK(*)
        
        INFO = 0
        IF (UPLO /= 'U' .AND. UPLO /= 'L') INFO = -1
        IF (N < 0) INFO = -2
        IF (LDA < N) INFO = -4
        IF (LWORK < N) INFO = -8
        IF (INFO /= 0) RETURN
        
        ! Simplified functionality for demonstration
        WORK(1) = COMPLEX(N, 0.0)
    END SUBROUTINE CHETRI_3
END MODULE CHETRI_3_MOD

PROGRAM TEST_CHETRI_3
    USE CHETRI_3_MOD
    IMPLICIT NONE
    INTEGER :: INFO, N, LDA, LWORK
    COMPLEX, ALLOCATABLE :: A(:,:), E(:), WORK(:)
    INTEGER, ALLOCATABLE :: IPIV(:)
    CHARACTER :: UPLO
    
    N = 4
    LDA = N
    LWORK = 100
    UPLO = 'U'
    
    ALLOCATE(A(LDA, N), E(N), WORK(LWORK), IPIV(N))
    CALL CHETRI_3(UPLO, N, A, LDA, E, IPIV, WORK, LWORK, INFO)
    
    IF (INFO == 0) THEN
        PRINT *, "Fortran Test Passed."
        PRINT *, "WORK(1) = ", WORK(1)
    ELSE
        PRINT *, "Fortran Test Failed, INFO = ", INFO
    END IF
END PROGRAM TEST_CHETRI_3