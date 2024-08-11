program test_erd_normalize_cartesian
    implicit none

    integer, parameter :: M = 3, NXYZ = 6, L = 2
    double precision :: NORM(0:L)
    double precision :: BATCH(1:M, 1:NXYZ)
    integer :: i, j

    ! Initialize NORM array
    NORM(0) = 1.0D0
    NORM(1) = 2.0D0
    NORM(2) = 3.0D0

    ! Initialize BATCH array
    do i = 1, M
        do j = 1, NXYZ
            BATCH(i, j) = 1.0D0
        end do
    end do

    ! Call the subroutine
    call ERD__NORMALIZE_CARTESIAN(M, NXYZ, L, NORM, BATCH)

    ! Print the results for verification
    print *, 'BATCH after normalization:'
    do i = 1, M
        print *, BATCH(i, :)
    end do

contains

    SUBROUTINE ERD__NORMALIZE_CARTESIAN(M, NXYZ, L, NORM, BATCH)
        IMPLICIT NONE

        INTEGER :: I, L, M, N, X, Y, Z
        INTEGER :: NXYZ
        INTEGER :: YBEG

        DOUBLE PRECISION :: SCALAR
        DOUBLE PRECISION :: XNORM

        DOUBLE PRECISION :: NORM(0:L)
        DOUBLE PRECISION :: BATCH(1:M, 1:NXYZ)

        N = 0

        DO X = L, 0, -1
            XNORM = NORM(X)
            YBEG = L - X
            DO Y = YBEG, 0, -1
                Z = YBEG - Y
                SCALAR = XNORM * NORM(Y) * NORM(Z)

                N = N + 1

                DO I = 1, M
                    BATCH(I, N) = SCALAR * BATCH(I, N)
                END DO
            END DO
        END DO

        RETURN
    END SUBROUTINE ERD__NORMALIZE_CARTESIAN

end program test_erd_normalize_cartesian