PROGRAM arrayTest
  INTEGER array(1:2,-1:1)
  DATA array/11,21,12,22,13,23/
  INTEGER i, j

  DO i = 1, 2
    DO j = -1, 1
      PRINT *, 'array(', i, ',', j, ') = ', array(i, j)
    END DO
  END DO

  STOP
END PROGRAM arrayTest