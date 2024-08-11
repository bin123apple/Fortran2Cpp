PROGRAM TEST_SAXPY
    IMPLICIT NONE
    REAL, DIMENSION(5) :: SX, SY
    INTEGER :: I

    ! Initialize the vectors
    SX = (/ 1.0, 2.0, 3.0, 4.0, 5.0 /)
    SY = (/ 5.0, 4.0, 3.0, 2.0, 1.0 /)
    
    ! Call SAXPY with N=5, SA=2.0, INCX=1, INCY=1
    CALL SAXPY(5, 2.0, SX, 1, SY, 1)
    
    ! Print the result
    PRINT *, 'SY = ', SY
    
END PROGRAM TEST_SAXPY

SUBROUTINE SAXPY(N,SA,SX,INCX,SY,INCY)
    REAL SA
    INTEGER INCX,INCY,N
    REAL SX(*),SY(*)
    INTEGER I,IX,IY,M,MP1
    INTRINSIC MOD
    IF (N.LE.0) RETURN
    IF (SA.EQ.0.0) RETURN
    IF (INCX.EQ.1 .AND. INCY.EQ.1) THEN
        M = MOD(N,4)
        IF (M.NE.0) THEN
            DO I = 1,M
                SY(I) = SY(I) + SA*SX(I)
            END DO
        END IF
        IF (N.LT.4) RETURN
        MP1 = M + 1
        DO I = MP1,N,4
            SY(I) = SY(I) + SA*SX(I)
            SY(I+1) = SY(I+1) + SA*SX(I+1)
            SY(I+2) = SY(I+2) + SA*SX(I+2)
            SY(I+3) = SY(I+3) + SA*SX(I+3)
        END DO
    ELSE
        IX = 1
        IY = 1
        IF (INCX.LT.0) IX = (-N+1)*INCX + 1
        IF (INCY.LT.0) IY = (-N+1)*INCY + 1
        DO I = 1,N
            SY(IY) = SY(IY) + SA*SX(IX)
            IX = IX + INCX
            IY = IY + INCY
        END DO
    END IF
    RETURN
END SUBROUTINE SAXPY