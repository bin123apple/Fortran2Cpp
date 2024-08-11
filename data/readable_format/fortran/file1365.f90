PROGRAM test_sum_all_3darray
  IMPLICIT NONE

  REAL(KIND=8), ALLOCATABLE :: sendBuf(:,:,:), recvBuf(:,:,:)
  INTEGER(KIND=4) :: nx, ny, nz
  REAL(KIND=8) :: expectedSum, actualSum
  INTEGER :: i, j, k

  ! Example: 2x2x2 array
  nx = 2
  ny = 2
  nz = 2
  ALLOCATE(sendBuf(nx,ny,nz), recvBuf(nx,ny,nz))
  
  sendBuf = RESHAPE([1.0D0, 2.0D0, 3.0D0, 4.0D0, 5.0D0, 6.0D0, 7.0D0, 8.0D0], SHAPE(sendBuf))
  expectedSum = SUM(sendBuf)
  
  CALL SUM_ALL_3DARRAY_DP(sendBuf, recvBuf, nx, ny, nz)
  
  ! Check if recvBuf contains the correct sum
  actualSum = 0.0D0
  DO i = 1, nx
    DO j = 1, ny
      DO k = 1, nz
        actualSum = actualSum + recvBuf(i, j, k)
      END DO
    END DO
  END DO
  
  IF (ABS(actualSum - expectedSum * nx * ny * nz) < 1.0E-10) THEN
    PRINT *, "Test passed."
  ELSE
    PRINT *, "Test failed."
  END IF

  DEALLOCATE(sendBuf, recvBuf)

CONTAINS

  SUBROUTINE SUM_ALL_3DARRAY_DP(SENDBUF,RECVBUF,NX,NY,NZ)
    INTEGER(KIND=4), INTENT(IN) :: NX, NY, NZ
    REAL(KIND=8), INTENT(IN) :: SENDBUF(NX,NY,NZ)
    REAL(KIND=8), INTENT(OUT) :: RECVBUF(NX,NY,NZ)
    INTEGER :: i, j, k
    REAL(KIND=8) :: sum

    sum = 0.0D0
    DO i = 1, NX
      DO j = 1, NY
        DO k = 1, NZ
          sum = sum + SENDBUF(i, j, k)
        END DO
      END DO
    END DO
    
    DO i = 1, NX
      DO j = 1, NY
        DO k = 1, NZ
          RECVBUF(i, j, k) = sum
        END DO
      END DO
    END DO
  END SUBROUTINE SUM_ALL_3DARRAY_DP

END PROGRAM test_sum_all_3darray