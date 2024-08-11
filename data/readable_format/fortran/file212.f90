! covsrt.f90
SUBROUTINE COVSRT(COVAR,NCVM,MA,LISTA,MFIT)
    IMPLICIT NONE
    INTEGER NCVM,MA,MFIT
    INTEGER LISTA(MFIT)
    REAL*8 COVAR(NCVM,NCVM) 
    REAL*8 SWAP
    INTEGER I,J,K

    DO J=1,MA
        DO I=1,MA
            COVAR(I,J) = 0.0D0
        END DO
    END DO

    DO I=1,MFIT
        COVAR(LISTA(I),LISTA(I)) = 1.0D0
    END DO

    DO 20 J=1,MA
        DO 10 I=1,MA
            IF (I.EQ.J) THEN
                COVAR(I,J) = 1.0D0
            ELSE
                COVAR(I,J) = 0.0D0
            ENDIF
10      CONTINUE
20   CONTINUE

END SUBROUTINE COVSRT

PROGRAM TestCovsrt
    IMPLICIT NONE
    INTEGER, PARAMETER :: MA = 3, MFIT = 2, NCVM = 3
    REAL*8, DIMENSION(NCVM,NCVM) :: COVAR
    INTEGER, DIMENSION(MFIT) :: LISTA
    INTEGER :: I, J

    ! Initialize COVAR and LISTA
    COVAR = 0
    LISTA = [1, 3]

    ! Call the subroutine
    CALL COVSRT(COVAR, NCVM, MA, LISTA, MFIT)

    ! Print the result
    PRINT *, 'Modified COVAR:'
    DO I = 1, NCVM
        WRITE(*, '(3F8.3)') COVAR(I,:)
    END DO

END PROGRAM TestCovsrt