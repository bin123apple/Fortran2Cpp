! sla_DCS2C.f90
SUBROUTINE sla_DCS2C (A, B, V)
  IMPLICIT NONE
  DOUBLE PRECISION A, B, V(3)
  DOUBLE PRECISION COSB
  COSB = COS(B)
  V(1) = COS(A) * COSB
  V(2) = SIN(A) * COSB
  V(3) = SIN(B)
END SUBROUTINE sla_DCS2C

PROGRAM test_sla_DCS2C
  IMPLICIT NONE
  DOUBLE PRECISION V(3)
  DOUBLE PRECISION A, B
  INTEGER :: i

  ! Test case 1
  A = 0.0D0
  B = 0.0D0
  CALL sla_DCS2C(A, B, V)
  PRINT *, "Test case 1: A =", A, "B =", B
  DO i = 1, 3
     PRINT *, "V(", i, ") = ", V(i)
  END DO

  ! Test case 2
  A = 3.14159265358979323846D0 / 4.0D0
  B = 3.14159265358979323846D0 / 4.0D0
  CALL sla_DCS2C(A, B, V)
  PRINT *, "Test case 2: A =", A, "B =", B
  DO i = 1, 3
     PRINT *, "V(", i, ") = ", V(i)
  END DO
END PROGRAM test_sla_DCS2C