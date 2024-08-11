MODULE mo_column
  IMPLICIT NONE
  PUBLIC :: ty_column

  TYPE :: ty_column
  CONTAINS
    PROCEDURE :: compute_column
  END TYPE ty_column

CONTAINS

  SUBROUTINE compute_column(this, nz, q, t, nproma)
    CLASS(ty_column), INTENT(INOUT) :: this
    INTEGER, INTENT(IN) :: nz, nproma
    REAL, INTENT(INOUT) :: t(:,:), q(:,:)

    INTEGER :: i, j
    DO i = 1, nz
      DO j = 1, nproma
        q(i, j) = q(i, j) * 2.0
        t(i, j) = t(i, j) + 10.0
      END DO
    END DO
  END SUBROUTINE compute_column

END MODULE mo_column

MODULE mo_column_extra
  USE mo_column, ONLY: ty_column

CONTAINS

  SUBROUTINE compute_one(nz, q, t, nproma)
    INTEGER, INTENT(IN) :: nproma
    INTEGER, INTENT(IN) :: nz
    REAL, INTENT(INOUT) :: t(:, :)
    REAL, INTENT(INOUT) :: q(:, :)
    TYPE(ty_column) :: column

    CALL column % compute_column(nz, q, t, nproma=nproma)
  END SUBROUTINE compute_one

END MODULE mo_column_extra

PROGRAM test_compute_one
  USE mo_column_extra
  IMPLICIT NONE

  INTEGER :: nz, nproma
  REAL, ALLOCATABLE :: t(:,:), q(:,:)

  nz = 2
  nproma = 1
  ALLOCATE(t(nz, nproma), q(nz, nproma))
  t = RESHAPE(SOURCE = [1.0, 2.0], SHAPE = [nz, nproma])
  q = RESHAPE(SOURCE = [3.0, 4.0], SHAPE = [nz, nproma])

  CALL compute_one(nz, q, t, nproma)

  PRINT *, "Updated t:"
  PRINT *, t
  PRINT *, "Updated q:"
  PRINT *, q

  DEALLOCATE(t, q)

END PROGRAM test_compute_one