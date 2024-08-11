program test_idamax
  implicit none
  integer :: idamax, n, incx, result
  double precision :: dx(5)
  
  ! Test data
  n = 5
  incx = 1
  dx = (/1.0d0, 3.0d0, -5.0d0, 2.0d0, 4.0d0/)
  
  ! Call the IDAMAX function
  result = idamax(n, dx, incx)
  
  ! Print the result
  print *, 'IDAMAX result:', result
end program test_idamax

INTEGER FUNCTION IDAMAX (N, DX, INCX)
  DOUBLE PRECISION DX(*), DMAX, XMAG
  INTEGER I, INCX, IX, N
  IDAMAX = 0
  IF (N .LE. 0) RETURN
  IDAMAX = 1
  IF (N .EQ. 1) RETURN
  IF (INCX .EQ. 1) GOTO 20
  IX = 1
  IF (INCX .LT. 0) IX = (-N+1)*INCX + 1
  DMAX = ABS(DX(IX))
  IX = IX + INCX
  DO 10 I = 2,N
    XMAG = ABS(DX(IX))
    IF (XMAG .GT. DMAX) THEN
      IDAMAX = I
      DMAX = XMAG
    ENDIF
    IX = IX + INCX
  10 CONTINUE
  RETURN
20 DMAX = ABS(DX(1))
  DO 30 I = 2,N
    XMAG = ABS(DX(I))
    IF (XMAG .GT. DMAX) THEN
      IDAMAX = I
      DMAX = XMAG
    ENDIF
  30 CONTINUE
  RETURN
END