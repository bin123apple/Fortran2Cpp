MODULE mo_column
  CONTAINS
    SUBROUTINE compute(nz, q, t, s, nproma)
      INTEGER, INTENT(IN) :: nz, nproma
      REAL, INTENT(INOUT) :: q(nproma, nz), t(nproma, nz), s(nproma)
      CALL compute_column(nz, q, t, s, nproma)
    END SUBROUTINE compute

    SUBROUTINE compute_column(nz, q, t, s, nproma)
      INTEGER, INTENT(IN) :: nz, nproma
      REAL, INTENT(INOUT) :: q(nproma, nz), t(nproma, nz), s(nproma)
      REAL, ALLOCATABLE :: y(:)
      INTEGER :: k, proma
      REAL :: c = 5.345

      ALLOCATE(y(nz))
      y = 0.0

      DO k = 2, nz
        DO proma = 1, nproma
          t(proma, k) = c * k
          y(k) = t(proma, k) + s(proma)
          q(proma, k) = q(proma, k-1) + t(proma, k) * c + y(k)
        END DO
      END DO

      DO proma = 1, nproma
        q(proma, nz) = q(proma, nz) * c
      END DO

      DEALLOCATE(y)
    END SUBROUTINE compute_column
END MODULE mo_column

PROGRAM test_mo_column
  USE mo_column
  IMPLICIT NONE

  INTEGER :: nz = 10, nproma = 5
  REAL, ALLOCATABLE :: q(:, :), t(:, :), s(:)
  INTEGER :: i, j

  ALLOCATE(q(nproma, nz), t(nproma, nz), s(nproma))
  q = 0.0
  t = 0.0
  s = 1.0

  CALL compute(nz, q, t, s, nproma)

  DO i = 1, nproma
    DO j = 1, nz
      PRINT *, 'q(', i, ',', j, ') = ', q(i, j)
    END DO
  END DO

  DEALLOCATE(q, t, s)
END PROGRAM test_mo_column