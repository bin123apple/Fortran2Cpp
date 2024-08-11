PROGRAM TestBalbak
    IMPLICIT NONE
    INTEGER, PARAMETER :: NM = 5, N = 3, LOW = 2, IGH = 4, M = 2
    REAL :: SCALE(NM), Z(NM,M)
    INTEGER :: i, j

    ! Initialize SCALE with some test values
    DO i = 1, NM
        SCALE(i) = REAL(i)
    END DO

    ! Initialize Z with some test values
    DO i = 1, NM
        DO j = 1, M
            Z(i,j) = REAL(i*j)
        END DO
    END DO

    ! Call the BALBAK subroutine
    CALL BALBAK(NM, N, LOW, IGH, SCALE, M, Z)

    ! Output the modified Z for inspection
    PRINT *, 'Modified Z:'
    DO i = 1, NM
        WRITE(*,*) (Z(i,j), j = 1, M)
    END DO

CONTAINS

    SUBROUTINE BALBAK(NM, N, LOW, IGH, SCALE, M, Z)
        INTEGER :: NM, N, LOW, IGH, M
        REAL, DIMENSION(*) :: SCALE
        REAL, DIMENSION(NM,M) :: Z
        INTEGER :: I, J, K, II
        REAL :: S

        IF (M .EQ. 0) RETURN
        IF (IGH .EQ. LOW) RETURN

        DO I = LOW, IGH
            S = SCALE(I)
            DO J = 1, M
                Z(I,J) = Z(I,J) * S
            END DO
        END DO

        DO II = 1, N
            I = II
            IF (I .GE. LOW .AND. I .LE. IGH) CYCLE
            IF (I .LT. LOW) I = LOW - II
            K = NINT(SCALE(I)) ! Assuming SCALE holds approximate integer values
            IF (K .EQ. I) CYCLE
            DO J = 1, M
                S = Z(I,J)
                Z(I,J) = Z(K,J)
                Z(K,J) = S
            END DO
        END DO

    END SUBROUTINE BALBAK

END PROGRAM TestBalbak