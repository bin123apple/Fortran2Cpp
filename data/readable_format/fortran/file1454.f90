MODULE mo_column
  IMPLICIT NONE
CONTAINS

  SUBROUTINE compute(nz, q, t, z)
    IMPLICIT NONE
    INTEGER, INTENT(IN) :: nz
    REAL, INTENT(INOUT) :: t(:)
    REAL, INTENT(INOUT) :: q(:)
    REAL, INTENT(INOUT) :: z
    CALL compute_column(nz, q, t, z)
  END SUBROUTINE compute

  SUBROUTINE compute_column(nz, q, t, z)
    IMPLICIT NONE
    INTEGER, INTENT(IN) :: nz
    REAL, INTENT(INOUT) :: t(:)
    REAL, INTENT(INOUT) :: q(:)
    REAL, INTENT(INOUT) :: z
    INTEGER :: k
    REAL :: c

    c = 5.345
    DO k = 2, nz
      t(k) = c * k
      q(k) = q(k - 1) + t(k) * c
    END DO
    q(nz) = q(nz) * c
  END SUBROUTINE compute_column

END MODULE mo_column

PROGRAM test_mo_column
  USE mo_column
  IMPLICIT NONE
  INTEGER, PARAMETER :: nz = 5
  REAL, DIMENSION(nz) :: q, t
  REAL :: z
  INTEGER :: i

  ! Initialize inputs
  q = (/0.0, 0.0, 0.0, 0.0, 0.0/)
  t = (/0.0, 0.0, 0.0, 0.0, 0.0/)
  z = 0.0

  ! Call the compute subroutine
  CALL compute(nz, q, t, z)

  ! Output results for manual verification
  PRINT *, 'q:', q
  PRINT *, 't:', t
  PRINT *, 'Expected q and t values should be calculated according to the compute_column logic.'

END PROGRAM test_mo_column