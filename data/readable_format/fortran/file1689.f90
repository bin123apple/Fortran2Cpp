PROGRAM TestDSDOT
    IMPLICIT NONE
    INTEGER :: n
    REAL, ALLOCATABLE :: sx(:), sy(:)
    DOUBLE PRECISION :: result
    INTEGER :: incx, incy

    ! Test 1: Basic functionality
    n = 4
    ALLOCATE(sx(n), sy(n))
    sx = (/1.0, 2.0, 3.0, 4.0/)
    sy = (/1.0, 1.0, 1.0, 1.0/)
    incx = 1
    incy = 1
    result = DSDOT(n, sx, incx, sy, incy)
    PRINT *, "Test 1 Result: ", result  ! Expected: 10.0

    ! Test 2: Positive increments
    sx = (/1.0, -1.0, 2.0, -2.0/)
    sy = (/1.0, 2.0, 3.0, 4.0/)
    incx = 2
    incy = 2
    result = DSDOT(n, sx, incx, sy, incy)
    PRINT *, "Test 2 Result: ", result  ! Expected: 7.0

    ! Test 3: Zero and negative increments
    sx = (/2.0, 0.0, -2.0, 0.0/)
    sy = (/0.0, 3.0, 0.0, -3.0/)
    incx = -1
    incy = -1
    result = DSDOT(2, sx, incx, sy, incy)
    PRINT *, "Test 3 Result: ", result  ! Expected: 6.0

    DEALLOCATE(sx, sy)

CONTAINS

    DOUBLE PRECISION FUNCTION DSDOT(N,SX,INCX,SY,INCY)
        INTEGER, INTENT(IN) :: N, INCX, INCY
        REAL, INTENT(IN) :: SX(*), SY(*)

        INTEGER I,KX,KY,NS

        DSDOT = 0.0D0
        IF (N.LE.0) RETURN
        IF (INCX.EQ.INCY .AND. INCX.GT.0) THEN
            NS = N*INCX
            DO I = 1,NS,INCX
                DSDOT = DSDOT + DBLE(SX(I))*DBLE(SY(I))
            END DO
        ELSE
            KX = 1
            KY = 1
            IF (INCX.LT.0) KX = 1 + (1-N)*INCX
            IF (INCY.LT.0) KY = 1 + (1-N)*INCY
            DO I = 1,N
                DSDOT = DSDOT + DBLE(SX(KX))*DBLE(SY(KY))
                KX = KX + INCX
                KY = KY + INCY
            END DO
        END IF
        RETURN
    END FUNCTION DSDOT

END PROGRAM TestDSDOT