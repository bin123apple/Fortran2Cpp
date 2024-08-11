PROGRAM testCROT
  IMPLICIT NONE
  INTEGER, PARAMETER :: N = 3
  REAL, PARAMETER :: C = 0.5
  COMPLEX :: S = (0.0, 1.0)
  COMPLEX :: CX(N) = [(1.0, 2.0), (3.0, 4.0), (5.0, 6.0)]
  COMPLEX :: CY(N) = [(7.0, 8.0), (9.0, 10.0), (11.0, 12.0)]
  INTEGER :: I

  CALL CROT(N, CX, 1, CY, 1, C, S)

  PRINT *, 'CX:'
  DO I = 1, N
    PRINT '(F4.1, ", ", F4.1)', CX(I)
  END DO

  PRINT *, 'CY:'
  DO I = 1, N
    PRINT '(F4.1, ", ", F4.1)', CY(I)
  END DO

CONTAINS

  SUBROUTINE CROT( N, CX, INCX, CY, INCY, C, S )
    INTEGER            INCX, INCY, N
    REAL               C
    COMPLEX            S
    COMPLEX            CX( * ), CY( * )

    INTEGER            I, IX, IY
    COMPLEX            STEMP
    INTRINSIC          CONJG

    IF( N.LE.0 ) THEN
      RETURN
    END IF

    IX = 1
    IY = 1
    IF( INCX.LT.0 ) THEN
      IX = ( -N+1 )*INCX + 1
    END IF
    IF( INCY.LT.0 ) THEN
      IY = ( -N+1 )*INCY + 1
    END IF

    DO I = 1, N
      STEMP = C*CX( IX ) + S*CY( IY )
      CY( IY ) = C*CY( IY ) - CONJG( S )*CX( IX )
      CX( IX ) = STEMP
      IX = IX + INCX
      IY = IY + INCY
    END DO

  END SUBROUTINE CROT

END PROGRAM testCROT