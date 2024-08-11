PROGRAM TestDscal
  IMPLICIT NONE
  INTEGER :: i
  DOUBLE PRECISION, ALLOCATABLE :: arr(:)
  INTEGER :: size
  DOUBLE PRECISION :: factor
  INTEGER :: stride

  ! Test 1: Stride of 1, size not a multiple of 5
  size = 7
  ALLOCATE(arr(size))
  arr = (/1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0/)
  factor = 2.0
  stride = 1
  CALL DSCAL(size, factor, arr, stride)
  PRINT *, "Test 1", arr
  
  ! Test 2: Stride of 1, size a multiple of 5
  size = 10
  arr = (/1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0/)
  CALL DSCAL(size, factor, arr, stride)
  PRINT *, "Test 2", arr
  
  ! Test 3: A negative stride
  size = 5
  arr = (/1.0, 2.0, 3.0, 4.0, 5.0/)
  stride = -1
  CALL DSCAL(size, factor, arr, stride)
  PRINT *, "Test 3", arr
  
  ! Test 4: A non-unit positive stride
  size = 6
  arr = (/1.0, 2.0, 3.0, 4.0, 5.0, 6.0/)
  stride = 2
  CALL DSCAL(size, factor, arr, stride)
  PRINT *, "Test 4", arr
  
  ! Test 5: An empty array (n = 0)
  size = 0
  CALL DSCAL(size, factor, arr, stride)
  PRINT *, "Test 5", "No output expected"

  DEALLOCATE(arr)

CONTAINS

  SUBROUTINE DSCAL(N, DA, DX, INCX)
    DOUBLE PRECISION DA, DX(*)
    INTEGER I, INCX, IX, M, MP1, N
    IF (N .LE. 0) RETURN
    IF (INCX .EQ. 1) THEN
      M = MOD(N,5)
      IF (M .NE. 0) THEN
        DO I = 1,M
          DX(I) = DA*DX(I)
        END DO
        IF (N .LT. 5) RETURN
      END IF
      MP1 = M + 1
      DO I = MP1,N,5
        DX(I) = DA*DX(I)
        DX(I+1) = DA*DX(I+1)
        DX(I+2) = DA*DX(I+2)
        DX(I+3) = DA*DX(I+3)
        DX(I+4) = DA*DX(I+4)
      END DO
    ELSE
      IX = 1
      IF (INCX .LT. 0) IX = (-N+1)*INCX + 1
      DO I = 1,N
        DX(IX) = DA*DX(IX)
        IX = IX + INCX
      END DO
    END IF
  END SUBROUTINE DSCAL

END PROGRAM TestDscal