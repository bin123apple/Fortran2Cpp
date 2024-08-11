PROGRAM main
  IMPLICIT NONE
  INTEGER, PARAMETER :: nproma = 2, nz = 3, b = 3
  REAL :: t(b, nproma)
  REAL :: q(b, nproma)
  INTEGER :: i, j

  ! Initialize arrays
  t = 0.0
  q = 0.0

  ! Call the compute subroutine
  CALL compute(nz, b, q, t, nproma)

  ! Output the results for inspection
  PRINT *, 'Results for T:'
  DO i = 1, b
    PRINT *, (t(i, j), j = 1, nproma)
  END DO

  PRINT *, 'Results for Q:'
  DO i = 1, b
    PRINT *, (q(i, j), j = 1, nproma)
  END DO

CONTAINS

  FUNCTION compute_column(nz, b, q, t, nproma) RESULT(r)
    INTEGER, INTENT(IN) :: nproma
    INTEGER, INTENT(IN) :: nz
    INTEGER, INTENT(IN) :: b
    REAL, INTENT(INOUT) :: t(1:b, 1:nproma)
    REAL, INTENT(INOUT) :: q(1:b, 1:nproma)
    INTEGER :: k, proma
    REAL :: c
    INTEGER :: r

    c = 5.345
    DO k = 2, nz
      DO proma = 1, nproma
        t(k, proma) = c * k
        q(k, proma) = q(k - 1, proma) + t(k, proma) * c
      END DO
    END DO
    DO proma = 1, nproma
      q(nz, proma) = q(nz, proma) * c
    END DO
    r = 0
  END FUNCTION compute_column

  SUBROUTINE compute(nz, b, q, t, nproma)
    INTEGER, INTENT(IN) :: nproma
    INTEGER, INTENT(IN) :: nz
    INTEGER, INTENT(IN) :: b
    REAL, INTENT(INOUT) :: t(1:b, 1:nproma)
    REAL, INTENT(INOUT) :: q(1:b, 1:nproma)
    INTEGER :: result

    result = compute_column(nz, b, q, t, nproma)
  END SUBROUTINE compute

END PROGRAM main