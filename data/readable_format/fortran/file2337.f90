MODULE mo_column

CONTAINS

  SUBROUTINE compute (nz, q, t, s, nproma)
    INTEGER, INTENT(IN) :: nproma

    INTEGER, INTENT(IN) :: nz
    REAL, INTENT(INOUT) :: t(:, :)
    REAL, INTENT(INOUT) :: q(:, :)
    REAL, INTENT(INOUT) :: s(1:nproma)

    CALL compute_column(nz, q, t, s, nproma=nproma)
  END SUBROUTINE compute

  SUBROUTINE compute_column(nz, q, t, s, nproma)
    INTEGER, INTENT(IN) :: nproma

    INTEGER, INTENT(IN) :: nz
    REAL, INTENT(INOUT) :: t(:, :)
    REAL, INTENT(INOUT) :: q(:, :)
    REAL, INTENT(INOUT) :: s(1:nproma)
    REAL, ALLOCATABLE :: y(:, :)
    INTEGER :: k
    REAL :: c
    INTEGER :: proma

    IF (.NOT. ALLOCATED(y)) THEN
      ALLOCATE(y(nproma, nz))
    END IF

    DO proma = 1, nproma, 1
      c = 5.345

      DO k = 2, nz, 1
        t(proma, k) = c * k
        y(proma, k) = t(proma, k) + s(proma)
        q(proma, k) = q(proma, k - 1) + t(proma, k) * c + y(proma, k)
      END DO
      q(proma, nz) = q(proma, nz) * c
    END DO

    IF (ALLOCATED(y)) THEN
      DEALLOCATE(y)
    END IF
  END SUBROUTINE compute_column

END MODULE mo_column

PROGRAM test_compute
  USE mo_column

  IMPLICIT NONE

  INTEGER :: nproma
  INTEGER :: nz
  REAL, ALLOCATABLE :: t(:,:)
  REAL, ALLOCATABLE :: q(:,:)
  REAL, ALLOCATABLE :: s(:)
  INTEGER :: i, j

  nproma = 3
  nz = 5

  ALLOCATE(t(nproma, nz))
  ALLOCATE(q(nproma, nz))
  ALLOCATE(s(nproma))

  ! Initialize test data
  t = 0.0
  q = 0.0
  s = 1.0

  ! Call the compute subroutine
  CALL compute(nz, q, t, s, nproma)

  ! Print results for verification
  PRINT *, "Results:"
  DO i = 1, nproma
    DO j = 1, nz
      PRINT *, "t(", i, ",", j, ") = ", t(i, j), " q(", i, ",", j, ") = ", q(i, j)
    END DO
  END DO

  ! Deallocate arrays
  DEALLOCATE(t)
  DEALLOCATE(q)
  DEALLOCATE(s)

END PROGRAM test_compute