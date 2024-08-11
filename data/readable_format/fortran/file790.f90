MODULE mo_column
  IMPLICIT NONE
CONTAINS
  FUNCTION compute_column(nz, q, t, nproma) RESULT(res)
    INTEGER, INTENT(IN) :: nz, nproma
    REAL, INTENT(INOUT) :: t(nz, nproma)
    REAL, INTENT(INOUT) :: q(nproma, nz)
    REAL :: res(nz, nproma)
    INTEGER :: k, proma
    REAL :: c = 5.345

    DO proma = 1, nproma
      DO k = 2, nz
        t(k, proma) = c * k
        q(proma, k) = t(k-1, proma) + t(k, proma) * c
      END DO
      q(proma, nz) = q(proma, nz) * c
      res(:, proma) = t(:, proma)
    END DO
  END FUNCTION compute_column

  SUBROUTINE compute_all(nz, q, t, nproma)
    INTEGER, INTENT(IN) :: nz, nproma
    REAL, INTENT(INOUT) :: t(nz, nproma)
    REAL, INTENT(INOUT) :: q(nproma, nz)
    REAL :: res(nz, nproma)
    INTEGER :: k, proma

    res = compute_column(nz, q, t, nproma)
  END SUBROUTINE compute_all
END MODULE mo_column

PROGRAM test_mo_column
  USE mo_column
  IMPLICIT NONE
  INTEGER, PARAMETER :: nz = 3, nproma = 2
  REAL :: t(nz, nproma), q(nproma, nz)
  INTEGER :: i, j

  ! Initialize t and q with some test data
  t = RESHAPE([1.0, 2.0, 3.0, 4.0, 5.0, 6.0], SHAPE(t))
  q = RESHAPE([6.0, 5.0, 4.0, 3.0, 2.0, 1.0], SHAPE(q))

  CALL compute_all(nz, q, t, nproma)

  PRINT *, "Testing compute_all:"
  DO i = 1, nz
     DO j = 1, nproma
        PRINT *, "t(", i, ",", j, ") = ", t(i, j)
        PRINT *, "q(", j, ",", i, ") = ", q(j, i)
     END DO
  END DO
END PROGRAM