MODULE mo_column
  IMPLICIT NONE
CONTAINS
  SUBROUTINE compute_column(nz, q, t)
    IMPLICIT NONE
    INTEGER, INTENT(IN)   :: nz
    REAL, INTENT(INOUT)   :: t(:)
    REAL, INTENT(INOUT)   :: q(:)
    INTEGER :: k
    REAL :: c
    
    c = 5.345
    c = c * c
    DO k = 2, nz
      t(k) = c * k
      q(k) = q(k - 1) + t(k) * c
    END DO
    
    IF (q(nz) > 0.0) THEN
      q(nz) = q(nz) * c
    END IF
  END SUBROUTINE compute_column
END MODULE mo_column

PROGRAM testComputeColumn
  USE mo_column
  IMPLICIT NONE
  
  INTEGER :: nz, i
  REAL, ALLOCATABLE :: t(:), q(:)
  
  ! Set size of arrays
  nz = 5
  
  ! Allocate arrays
  ALLOCATE(t(nz), q(nz))
  
  ! Initialize arrays
  t = 0.0
  q = 1.0
  
  ! Call subroutine
  CALL compute_column(nz, q, t)
  
  ! Print results for verification
  PRINT *, 't array:'
  DO i = 1, nz
    PRINT *, 't(', i, ') = ', t(i)
  END DO
  
  PRINT *, 'q array:'
  DO i = 1, nz
    PRINT *, 'q(', i, ') = ', q(i)
  END DO
  
  ! Deallocate arrays
  DEALLOCATE(t, q)
END PROGRAM testComputeColumn