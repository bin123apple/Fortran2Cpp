MODULE mo_column
  IMPLICIT NONE

CONTAINS

  FUNCTION compute_column(nz, q, t, nproma) RESULT(res)
    INTEGER, INTENT(IN) :: nproma, nz
    REAL, INTENT(INOUT) :: t(nz, nproma), q(nproma, nz)
    REAL :: res(nz, nproma)
    INTEGER :: k, proma
    REAL :: c

    c = 5.345
    DO k = 2, nz
      DO proma = 1, nproma
        t(k, proma) = c * k
        q(proma, k) = t(k - 1, proma) + t(k, proma) * c
      END DO
    END DO
    DO proma = 1, nproma
      q(proma, nz) = q(proma, nz) * c
    END DO
    res = t
  END FUNCTION compute_column

  SUBROUTINE compute_all(nz, q, t, nproma)
    INTEGER, INTENT(IN) :: nz, nproma
    REAL, INTENT(INOUT) :: t(nz, nproma), q(nproma, nz)
    REAL :: z(nproma, nz)
    INTEGER :: k, proma
    REAL :: res(nz, nproma)

    DO k = 1, nz
      DO proma = 1, nproma
        z(proma, k) = t(k, proma) + q(proma, k)
      END DO
    END DO
    res = compute_column(nz, q, t, nproma)
  END SUBROUTINE compute_all

END MODULE mo_column

PROGRAM test_mo_column
  USE mo_column
  IMPLICIT NONE
  INTEGER, PARAMETER :: nz = 5, nproma = 3
  REAL :: t(nz, nproma), q(nproma, nz)
  INTEGER :: i, j

  ! Initialize arrays
  t = 0.0
  q = 0.0

  CALL compute_all(nz, q, t, nproma)

  ! Output results for verification
  PRINT *, 'Matrix t:'
  DO i = 1, nz
    PRINT *, (t(i, j), j = 1, nproma)
  END DO

  PRINT *, 'Matrix q:'
  DO i = 1, nproma
    PRINT *, (q(i, j), j = 1, nz)
  END DO

END PROGRAM test_mo_column