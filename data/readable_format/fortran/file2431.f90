PROGRAM TestIDAMAX
    IMPLICIT NONE
    INTEGER :: result
    DOUBLE PRECISION, ALLOCATABLE :: DX(:)
    DOUBLE PRECISION :: DX3(3)
    
    ALLOCATE(DX(5))
    DX = (/ -1.0D0, 2.0D0, -3.0D0, 4.0D0, -5.0D0 /)

    WRITE(*,*) 'Fortran Tests:'
    result = IDAMAX(5, DX, 1)
    WRITE(*,*) 'Test case 1 (Expected 5): ', result
    
    result = IDAMAX(1, DX, 1)
    WRITE(*,*) 'Test case 2 (Expected 1): ', result
    
    result = IDAMAX(5, DX, -1)
    WRITE(*,*) 'Test case 3 (Expected 0): ', result
    
    result = IDAMAX(0, DX, 1)
    WRITE(*,*) 'Test case 4 (Expected 0): ', result
    
    DX3 = (/ -1.0D0, 2.0D0, -3.0D0 /) 
    result = IDAMAX(3, DX3, 2)
    WRITE(*,*) 'Test case 5 (Expected 1): ', result

CONTAINS

    INTEGER FUNCTION IDAMAX(N,DX,INCX)
        INTEGER INCX,N
        DOUBLE PRECISION, INTENT(IN) :: DX(*)
        DOUBLE PRECISION DMAX
        INTEGER I,IX
        INTRINSIC DABS

        IDAMAX = 0
        IF (N.LT.1 .OR. INCX.LE.0) RETURN
        IDAMAX = 1
        IF (N.EQ.1) RETURN
        IX = 1
        DMAX = DABS(DX(1))
        DO I = 2,N
            IX = IX + INCX
            IF (DABS(DX(IX)).GT.DMAX) THEN
                IDAMAX = (I-1)*INCX + 1
                DMAX = DABS(DX(IX))
            END IF
        END DO
        RETURN
    END FUNCTION IDAMAX

END PROGRAM TestIDAMAX