PROGRAM test_interp_trilinear
    IMPLICIT NONE
    REAL*8 :: di, dj, dk, velp
    REAL*4, DIMENSION(2,2,2) :: var

    ! Initialize test variables
    var = RESHAPE([1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0], SHAPE(var))
    di = 0.5
    dj = 0.5
    dk = 0.5

    ! Call the subroutine
    CALL interp_trilinear(di, dj, dk, var, velp)

    ! Display the result
    PRINT *, "Test 1: velp =", velp

    ! You can add more tests here following the same pattern

CONTAINS

    SUBROUTINE interp_trilinear(di, dj, dk, var, velp)
        IMPLICIT NONE
        REAL*8, INTENT(IN) :: di, dj, dk
        REAL*4, INTENT(IN), DIMENSION(2, 2, 2) :: var
        REAL*8, INTENT(OUT) :: velp
        REAL*8 :: i1, i2, i3, i4, j1, j2

        i1 = (var(2,1,1) - var(1,1,1)) * di + var(1,1,1)
        i2 = (var(2,1,2) - var(1,1,2)) * di + var(1,1,2)
        i3 = (var(2,2,2) - var(1,2,2)) * di + var(1,2,2)
        i4 = (var(2,2,1) - var(1,2,1)) * di + var(1,2,1)

        j1 = (i3 - i2) * dj + i2
        j2 = (i4 - i1) * dj + i1

        velp = (j1 - j2) * dk + j2
    END SUBROUTINE interp_trilinear

END PROGRAM test_interp_trilinear