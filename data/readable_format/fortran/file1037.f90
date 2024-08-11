! Define the MXCOPY subroutine
SUBROUTINE MXCOPY(N,MAT1,MAT2)
  INTEGER :: N, I, J
  REAL, DIMENSION(N,*) :: MAT1, MAT2
  
  IF (N .EQ. 4) THEN
    DO I=1, 4
      DO J=1, 4
        MAT2(I,J) = MAT1(I,J)
      END DO
    END DO
  ELSE
    DO I = 1,N
      DO J = 1,N
        MAT2(I,J) = MAT1(I,J)
      END DO
    END DO
  END IF
END SUBROUTINE MXCOPY

! Test program for MXCOPY
PROGRAM testMXCOPY
  REAL, ALLOCATABLE :: MAT1(:,:), MAT2(:,:)
  INTEGER :: N, I, J
  
  ! Test case 1: N = 4
  N = 4
  ALLOCATE(MAT1(N,N), MAT2(N,N))
  
  ! Initialize MAT1 with some values
  DO I = 1, N
    DO J = 1, N
      MAT1(I,J) = REAL(I*N + J)
    END DO
  END DO
  
  ! Call MXCOPY subroutine
  CALL MXCOPY(N, MAT1, MAT2)
  
  ! Print MAT2 for verification
  PRINT *, 'Test case 1: N = 4'
  DO I = 1, N
    PRINT *, (MAT2(I,J), J = 1, N)
  END DO
  
  DEALLOCATE(MAT1, MAT2)
  
  ! Test case 2: N = 5
  N = 5
  ALLOCATE(MAT1(N,N), MAT2(N,N))
  
  ! Initialize MAT1 with some values
  DO I = 1, N
    DO J = 1, N
      MAT1(I,J) = REAL(I*N + J)
    END DO
  END DO
  
  ! Call MXCOPY subroutine
  CALL MXCOPY(N, MAT1, MAT2)
  
  ! Print MAT2 for verification
  PRINT *, 'Test case 2: N = 5'
  DO I = 1, N
    PRINT *, (MAT2(I,J), J = 1, N)
  END DO
  
  DEALLOCATE(MAT1, MAT2)
END PROGRAM testMXCOPY