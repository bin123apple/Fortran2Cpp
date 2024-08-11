MODULE ZSwapModule
    IMPLICIT NONE
CONTAINS
    SUBROUTINE ZSWAP(N,ZX,INCX,ZY,INCY)
        INTEGER INCX,INCY,N
        COMPLEX*16 ZX(*),ZY(*)
        COMPLEX*16 ZTEMP
        INTEGER I,IX,IY
        IF (N.LE.0) RETURN
        IF (INCX.EQ.1 .AND. INCY.EQ.1) THEN
            DO I = 1,N
                ZTEMP = ZX(I)
                ZX(I) = ZY(I)
                ZY(I) = ZTEMP
            END DO
        ELSE
            IX = 1
            IY = 1
            IF (INCX.LT.0) IX = (-N+1)*INCX + 1
            IF (INCY.LT.0) IY = (-N+1)*INCY + 1
            DO I = 1,N
                ZTEMP = ZX(IX)
                ZX(IX) = ZY(IY)
                ZY(IY) = ZTEMP
                IX = IX + INCX
                IY = IY + INCY
            END DO
        END IF
    END SUBROUTINE ZSWAP
END MODULE ZSwapModule

PROGRAM testZSWAP
    USE ZSwapModule
    IMPLICIT NONE
    INTEGER :: i
    COMPLEX*16, ALLOCATABLE :: ZX(:), ZY(:)

    ! Test 1: Positive N, INCX = INCY = 1
    ALLOCATE(ZX(3), ZY(3))
    ZX = [(COMPLEX(i, i), i=1,3)]
    ZY = [(COMPLEX(-i, -i), i=1,3)]
    CALL ZSWAP(3, ZX, 1, ZY, 1)
    PRINT *, "Test 1 ZX:", ZX
    PRINT *, "Test 1 ZY:", ZY

    ! Test 2: Zero N
    CALL ZSWAP(0, ZX, 1, ZY, 1)
    PRINT *, "Test 2 ZX:", ZX
    PRINT *, "Test 2 ZY:", ZY

    ! Test 3: Negative INCX and INCY
    ZX = [(COMPLEX(i, i), i=1,3)]
    ZY = [(COMPLEX(-i, -i), i=1,3)]
    CALL ZSWAP(3, ZX, -1, ZY, -1)
    PRINT *, "Test 3 ZX:", ZX
    PRINT *, "Test 3 ZY:", ZY

    DEALLOCATE(ZX, ZY)
END PROGRAM testZSWAP