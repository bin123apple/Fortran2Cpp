PROGRAM MAIN
  INTEGER, ALLOCATABLE :: a(:)
  INTEGER :: i, sum

  ALLOCATE(a(1000))
  sum = 0

  ! Initialize array
  DO i = 1, 1000
    a(i) = 1
  END DO

  ! Calculate sum
  DO i = 1, 1000
    sum = sum + a(i)
  END DO

  ! Expected sum is 1000
  IF (sum == 1000) THEN
    PRINT *, "Test Passed!"
  ELSE
    PRINT *, "Test Failed!"
  END IF

  DEALLOCATE(a)
END PROGRAM MAIN