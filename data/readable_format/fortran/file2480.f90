MODULE mo_column

CONTAINS
 SUBROUTINE compute_column ( nz , q , t , nx , ny )
  INTEGER , INTENT(IN) :: ny
  INTEGER , INTENT(IN) :: nx

  INTEGER , INTENT(IN) :: nz
  REAL , INTENT(INOUT) :: t ( : , : , : )
  REAL , INTENT(INOUT) :: q ( : , : , : )
  INTEGER :: k
  REAL :: c
  REAL :: d
  INTEGER :: i
  INTEGER :: j

  c = 5.345
  DO k = 2 , nz , 1
   DO j = 1 , ny , 1
    DO i = 1 , nx , 1
     t ( i , j , k ) = c * k
     d = t ( i , j , k ) + c
     q ( i , j , k ) = q ( i , j , k - 1 ) + t ( i , j , k ) * c + d
    END DO
   END DO
  END DO
  DO j = 1 , ny , 1
   DO i = 1 , nx , 1
    q ( i , j , nz ) = q ( i , j , nz ) * c
   END DO
  END DO
 END SUBROUTINE compute_column

END MODULE mo_column

PROGRAM test_compute_column
  USE mo_column
  IMPLICIT NONE
  INTEGER :: nx, ny, nz
  REAL, ALLOCATABLE :: t(:,:,:)
  REAL, ALLOCATABLE :: q(:,:,:)
  INTEGER :: i, j, k

  nx = 3
  ny = 3
  nz = 3

  ALLOCATE(t(nx, ny, nz))
  ALLOCATE(q(nx, ny, nz))

  ! Initialize t and q arrays
  t = 0.0
  q = 1.0

  ! Call the subroutine
  CALL compute_column(nz, q, t, nx, ny)

  ! Print results for verification
  DO k = 1, nz
    DO j = 1, ny
      DO i = 1, nx
        PRINT *, 't(', i, ',', j, ',', k, ') = ', t(i, j, k), ', q(', i, ',', j, ',', k, ') = ', q(i, j, k)
      END DO
    END DO
  END DO

END PROGRAM test_compute_column