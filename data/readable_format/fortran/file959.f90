PROGRAM testDLA_GBRPVGRW
    IMPLICIT NONE
    DOUBLE PRECISION, ALLOCATABLE :: AB(:,:), AFB(:,:)
    DOUBLE PRECISION :: result
    INTEGER :: N, KL, KU, NCOLS, LDAB, LDAFB

    ! Define test case parameters
    N = 3
    KL = 1
    KU = 1
    NCOLS = 3
    LDAB = 3
    LDAFB = 3

    ! Allocate and initialize matrices
    ALLOCATE(AB(LDAB, NCOLS))
    ALLOCATE(AFB(LDAFB, NCOLS))
    AB = RESHAPE([1.0D0, 2.0D0, 3.0D0, 4.0D0, 5.0D0, 6.0D0, 7.0D0, 8.0D0, 9.0D0], SHAPE(AB))
    AFB = RESHAPE([1.0D0, 1.5D0, 2.5D0, 3.5D0, 4.5D0, 5.5D0, 6.5D0, 7.5D0, 8.5D0], SHAPE(AFB))

    ! Call the function
    result = DLA_GBRPVGRW(N, KL, KU, NCOLS, AB, LDAB, AFB, LDAFB)

    ! Output the result
    PRINT *, "Result: ", result

    ! Deallocate matrices
    DEALLOCATE(AB, AFB)

CONTAINS

    DOUBLE PRECISION FUNCTION DLA_GBRPVGRW(N, KL, KU, NCOLS, AB, LDAB, AFB, LDAFB)
        INTEGER, INTENT(IN) :: N, KL, KU, NCOLS, LDAB, LDAFB
        DOUBLE PRECISION, INTENT(IN) :: AB(LDAB, *), AFB(LDAFB, *)
        DOUBLE PRECISION :: RPVGRW

        INTEGER            :: I, J, KD
        DOUBLE PRECISION   :: AMAX, UMAX

        KD = KU + 1
        RPVGRW = 1.0D+0

        DO J = 1, NCOLS
            AMAX = 0.0D+0
            UMAX = 0.0D+0
            DO I = MAX(J-KU, 1), MIN(J+KL, N)
                AMAX = MAX(ABS(AB(KD+I-J, J)), AMAX)
            END DO
            DO I = MAX(J-KU, 1), J
                UMAX = MAX(ABS(AFB(KD+I-J, J)), UMAX)
            END DO
            IF (UMAX /= 0.0D+0) THEN
                RPVGRW = MIN(AMAX / UMAX, RPVGRW)
            END IF
        END DO
        DLA_GBRPVGRW = RPVGRW
    END FUNCTION DLA_GBRPVGRW

END PROGRAM testDLA_GBRPVGRW