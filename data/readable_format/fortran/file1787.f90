! Combined Fortran file with MXIDEN subroutine and test program
SUBROUTINE MXIDEN(N, MAT)
  INTEGER, INTENT(IN) :: N
  REAL, INTENT(OUT) :: MAT(N,N)
  INTEGER :: I, J

  IF (N .EQ. 4) THEN
    MAT = 0.0
    DO I = 1, N
      MAT(I,I) = 1.0
    END DO
  ELSE
    MAT = 0.0
    DO I = 1, N
      MAT(I,I) = 1.0
    END DO
  END IF
END SUBROUTINE MXIDEN

PROGRAM TestMXIDEN
  IMPLICIT NONE
  INTEGER, PARAMETER :: N1 = 4, N2 = 5
  REAL, ALLOCATABLE :: MAT(:,:)
  INTEGER :: I, J

  ! Test with N = 4
  ALLOCATE(MAT(N1,N1))
  CALL MXIDEN(N1, MAT)
  PRINT*, 'Testing N = 4'
  DO I = 1, N1
     PRINT*, (MAT(I,J), J=1,N1)
  END DO
  DEALLOCATE(MAT)

  ! Test with N not equal to 4
  ALLOCATE(MAT(N2,N2))
  CALL MXIDEN(N2, MAT)
  PRINT*, 'Testing N = 5'
  DO I = 1, N2
     PRINT*, (MAT(I,J), J=1,N2)
  END DO
  DEALLOCATE(MAT)
END PROGRAM TestMXIDEN