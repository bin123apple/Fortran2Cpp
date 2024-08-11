MODULE mo_column
  IMPLICIT NONE
CONTAINS
  SUBROUTINE compute_column(nz, q, t, nproma)
    INTEGER, INTENT(IN) :: nz, nproma
    REAL, INTENT(INOUT) :: t(nz, nproma)
    REAL, INTENT(INOUT) :: q(nz, nproma)
    INTEGER :: i, j

    DO i = 1, nz
       DO j = 1, nproma
          t(i, j) = t(i, j) + 1.0
          q(i, j) = q(i, j) + 1.0
       END DO
    END DO
  END SUBROUTINE compute_column
END MODULE mo_column

PROGRAM test_compute_column
  USE mo_column
  IMPLICIT NONE
  REAL, ALLOCATABLE :: t(:,:), q(:,:)
  INTEGER :: nz, nproma, i, j
  
  ! Initialize test parameters
  nz = 2
  nproma = 2
  ALLOCATE(t(nz,nproma), q(nz,nproma))
  
  ! Initialize arrays with zeros
  t = 0.0
  q = 0.0
  
  ! Call the subroutine
  CALL compute_column(nz, q, t, nproma)

  ! Output the results for verification
  PRINT *, "Array t after compute_column:"
  DO i = 1, nz
     PRINT *, (t(i, j), j = 1, nproma)
  END DO

  PRINT *, "Array q after compute_column:"
  DO i = 1, nz
     PRINT *, (q(i, j), j = 1, nproma)
  END DO
END PROGRAM test_compute_column