MODULE CLCTSXMOD
    IMPLICIT NONE
    CONTAINS
    LOGICAL FUNCTION CLCTSX(ALPHA, BETA)
        COMPLEX, INTENT(IN) :: ALPHA, BETA
        COMMON /MN/ M, N, MPLUSN, I, FS
        INTEGER M, N, MPLUSN, I
        LOGICAL FS

        IF (FS) THEN
            I = I + 1
            IF (I <= M) THEN
                CLCTSX = .FALSE.
            ELSE
                CLCTSX = .TRUE.
            END IF
            IF (I == MPLUSN) THEN
                FS = .FALSE.
                I = 0
            END IF
        ELSE
            I = I + 1
            IF (I <= N) THEN
                CLCTSX = .TRUE.
            ELSE
                CLCTSX = .FALSE.
            END IF
            IF (I == MPLUSN) THEN
                FS = .TRUE.
                I = 0
            END IF
        END IF
    END FUNCTION CLCTSX
END MODULE CLCTSXMOD

PROGRAM TestCLCTSX
    USE CLCTSXMOD
    IMPLICIT NONE
    COMPLEX :: ALPHA, BETA
    LOGICAL :: RESULT
    INTEGER :: TESTCASE

    ! Initialize common variables
    CALL INIT_COMMON()

    ! Initialize test variables
    ALPHA = (1.0, 1.0)
    BETA = (2.0, 2.0)

    ! Run test cases
    PRINT *, 'Running Fortran Tests:'
    DO TESTCASE = 1, 5
        RESULT = CLCTSX(ALPHA, BETA)
        PRINT *, 'Test ', TESTCASE, ': ', RESULT
    END DO
END PROGRAM TestCLCTSX

SUBROUTINE INIT_COMMON()
    COMMON /MN/ M, N, MPLUSN, I, FS
    INTEGER M, N, MPLUSN, I
    LOGICAL FS

    M = 2
    N = 3
    MPLUSN = M + N
    I = 0
    FS = .TRUE.
END SUBROUTINE INIT_COMMON