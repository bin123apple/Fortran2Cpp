PROGRAM test_second
  IMPLICIT NONE
  INTEGER :: count_rate, count_max
  INTEGER :: start, finish, elapsed

  ! Get clock rate
  CALL SYSTEM_CLOCK(COUNT_RATE = count_rate, COUNT_MAX = count_max)

  ! Get initial clock tick
  CALL SYSTEM_CLOCK(start)
  ! Simulate work by sleeping for 2 seconds
  CALL SLEEP(2)
  ! Get final clock tick
  CALL SYSTEM_CLOCK(finish)

  ! Calculate elapsed time in seconds
  elapsed = (finish - start) / count_rate

  PRINT *, 'Elapsed time should be close to 2 seconds: ', elapsed, ' seconds'
END PROGRAM test_second