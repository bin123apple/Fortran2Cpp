! File: astro_fortran.f90
SUBROUTINE iau_Apcg(DATE1, DATE2, EBPV, EHP, ASTROM)
  DOUBLE PRECISION DATE1, DATE2, EBPV(3,2), EHP(3), ASTROM(30)
  ! Placeholder logic for demonstration
  ASTROM(1) = DATE1 + DATE2
END SUBROUTINE iau_Apcg

SUBROUTINE iau_C2ixys(X, Y, S, ASTROM13)
  DOUBLE PRECISION X, Y, S, ASTROM13
  ! Placeholder logic for demonstration
  ASTROM13 = X + Y + S
END SUBROUTINE iau_C2ixys

SUBROUTINE iau_Apci(DATE1, DATE2, EBPV, EHP, X, Y, S, ASTROM)
  DOUBLE PRECISION DATE1, DATE2, EBPV(3,2), EHP(3), X, Y, S, ASTROM(30)
  CALL iau_Apcg(DATE1, DATE2, EBPV, EHP, ASTROM)
  CALL iau_C2ixys(X, Y, S, ASTROM(13))
END SUBROUTINE iau_Apci

PROGRAM TestApci
  IMPLICIT NONE
  DOUBLE PRECISION :: date1, date2, ebpv(3,2), ehp(3), x, y, s
  DOUBLE PRECISION :: astrom(30)
  INTEGER :: i

  date1 = 2451545.0
  date2 = 0.1
  ebpv = RESHAPE([0D0, 0D0, 0D0, 0D0, 0D0, 0D0], SHAPE(ebpv))
  ehp = [0D0, 0D0, 0D0]
  x = 0.1D0
  y = 0.2D0
  s = 0.3D0

  CALL iau_Apci(date1, date2, ebpv, ehp, x, y, s, astrom)

  PRINT *, "ASTROM:"
  DO i = 1, 30
    PRINT *, astrom(i)
  END DO
END PROGRAM TestApci