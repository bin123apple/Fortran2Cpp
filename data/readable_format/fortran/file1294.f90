PROGRAM ZROTTest
  IMPLICIT NONE
  INTEGER, PARAMETER :: N = 4
  INTEGER :: INCX, INCY
  DOUBLE PRECISION :: C
  COMPLEX*16 :: S
  COMPLEX*16 :: CX(N), CY(N)
  INTEGER :: i

  ! Initialize test values
  INCX = 1
  INCY = 1
  C = 0.5
  S = (0.5D0, 0.5D0)
  DO i = 1, N
    CX(i) = CMPLX(DFLOAT(i), -DFLOAT(i), KIND=8)
    CY(i) = CMPLX(-DFLOAT(i), DFLOAT(i), KIND=8)
  END DO

  ! Call the subroutine
  CALL ZROT(N, CX, INCX, CY, INCY, C, S)

  ! Output the results for verification
  PRINT *, 'CX:'
  DO i = 1, N
    PRINT *, CX(i)
  END DO
  PRINT *, 'CY:'
  DO i = 1, N
    PRINT *, CY(i)
  END DO

END PROGRAM ZROTTest

SUBROUTINE ZROT( N, CX, INCX, CY, INCY, C, S )
  INTEGER            INCX, INCY, N
  DOUBLE PRECISION   C
  COMPLEX*16         S
  COMPLEX*16         CX( * ), CY( * )

  INTEGER            I, IX, IY
  COMPLEX*16         STEMP

  IF( N.LE.0 ) RETURN
  IF( INCX.EQ.1 .AND. INCY.EQ.1 ) GO TO 20

  IX = 1
  IY = 1
  IF( INCX.LT.0 ) IX = ( -N+1 )*INCX + 1
  IF( INCY.LT.0 ) IY = ( -N+1 )*INCY + 1
  DO 10 I = 1, N
     STEMP = C*CX( IX ) + S*CY( IY )
     CY( IY ) = C*CY( IY ) - CONJG( S )*CX( IX )
     CX( IX ) = STEMP
     IX = IX + INCX
     IY = IY + INCY
10 CONTINUE
  RETURN

20 CONTINUE
  DO 30 I = 1, N
     STEMP = C*CX( I ) + S*CY( I )
     CY( I ) = C*CY( I ) - CONJG( S )*CX( I )
     CX( I ) = STEMP
30 CONTINUE
  RETURN
END