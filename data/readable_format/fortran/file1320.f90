MODULE mo_column
  IMPLICIT NONE
CONTAINS

  FUNCTION compute_column(nz, q, t) result(res)
    INTEGER, INTENT(IN) :: nz
    REAL, INTENT(INOUT) :: t(:)
    REAL, INTENT(INOUT) :: q(:)
    INTEGER :: k
    REAL :: c
    REAL :: res(1:nz)

    c = 5.345
    DO k = 2, nz
      t(k) = c * k
      q(k) = t(k - 1) + t(k) * c
    END DO
    q(nz) = q(nz) * c

    res = t
  END FUNCTION compute_column

  SUBROUTINE compute_all(nz, q, val)
    INTEGER, INTENT(IN) :: nz
    REAL, INTENT(INOUT) :: val(:)
    REAL, INTENT(INOUT) :: q(:)
    REAL :: res(1:nz)

    res(:) = compute_column(nz, q, val)
    ! Optionally, do something with res
    ! For demonstration, we are not modifying val based on res, but you can add logic as needed.
  END SUBROUTINE compute_all
END MODULE mo_column

PROGRAM test_mo_column
  USE mo_column
  IMPLICIT NONE
  INTEGER :: nz
  REAL, ALLOCATABLE :: q(:), val(:)
  INTEGER :: i

  ! Example test case
  nz = 5
  ALLOCATE(q(nz), val(nz))
  q = [0.0, 1.0, 2.0, 3.0, 4.0]
  val = [1.0, 2.0, 3.0, 4.0, 5.0]

  CALL compute_all(nz, q, val)

  ! Print results for demonstration
  PRINT *, "Modified q:"
  DO i = 1, nz
    PRINT *, q(i)
  END DO

  PRINT *, "Modified val:"
  DO i = 1, nz
    PRINT *, val(i)
  END DO

  DEALLOCATE(q, val)
END PROGRAM test_mo_column