MODULE mo_column

CONTAINS

SUBROUTINE compute_column (nz, q, t, l, nproma)
  INTEGER, INTENT(IN) :: nproma
  INTEGER, INTENT(IN) :: nz
  LOGICAL, INTENT(IN) :: l
  REAL, INTENT(INOUT) :: t(nproma, nz)
  REAL, INTENT(INOUT) :: q(nproma, nz)
  INTEGER :: k, proma
  REAL :: c

  IF (l) THEN
    c = 5.345
    DO proma = 1, nproma
      DO k = 2, nz
        t(proma, k) = c * k
        q(proma, k) = q(proma, k - 1) + t(proma, k) * c
      END DO
      q(proma, nz) = q(proma, nz) * c
    END DO
  END IF
END SUBROUTINE compute_column

END MODULE mo_column

PROGRAM test_compute_column
  USE mo_column
  IMPLICIT NONE
  INTEGER, PARAMETER :: nz = 5, nproma = 2
  REAL, ALLOCATABLE :: t(:,:), q(:,:)
  LOGICAL :: l
  INTEGER :: i, j

  ALLOCATE(t(nproma,nz), q(nproma,nz))
  t = 0.0
  q = 0.0
  l = .TRUE.

  CALL compute_column(nz, q, t, l, nproma)

  PRINT *, "Testing compute_column subroutine:"
  DO i = 1, nproma
    PRINT *, "ProMa =", i
    DO j = 1, nz
      PRINT *, "t(", i, ",", j, ") =", t(i, j), "q(", i, ",", j, ") =", q(i, j)
    END DO
  END DO

  DEALLOCATE(t, q)
END PROGRAM test_compute_column