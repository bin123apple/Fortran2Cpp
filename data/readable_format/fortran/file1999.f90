PROGRAM A28_3
  REAL :: X

  X = 1.0
  PRINT *, 'Before Parallel Region X:', X
!$OMP PARALLEL PRIVATE(X)
  X = 10
  PRINT *, 'Inside Parallel Region X:', X
!$OMP END PARALLEL
  PRINT *, 'After Parallel Region X:', X
END PROGRAM A28_3