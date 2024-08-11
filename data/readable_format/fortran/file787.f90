MODULE parallel_routines
  IMPLICIT NONE
CONTAINS
  SUBROUTINE PARALLEL_INIT(rank, npe)
    INTEGER, INTENT(OUT) :: rank, npe
    rank = 0
    npe = 1
  END SUBROUTINE PARALLEL_INIT

  SUBROUTINE PARALLEL_SUM(input, output, n)
    INTEGER, INTENT(IN) :: n
    DOUBLE PRECISION, INTENT(IN) :: input(*)
    DOUBLE PRECISION, INTENT(OUT) :: output(*)
    INTEGER :: i
    DO i = 1, n
      output(i) = input(i)
    END DO
  END SUBROUTINE PARALLEL_SUM

  SUBROUTINE PARALLEL_FINALIZE()
    ! This subroutine is intentionally left blank.
  END SUBROUTINE PARALLEL_FINALIZE
END MODULE parallel_routines

PROGRAM test_parallel_routines
  USE parallel_routines
  IMPLICIT NONE
  INTEGER :: rank, npe, i
  DOUBLE PRECISION :: input(5), output(5)
  
  CALL PARALLEL_INIT(rank, npe)
  IF (rank == 0 .AND. npe == 1) THEN
    PRINT *, 'PARALLEL_INIT test passed.'
  ELSE
    PRINT *, 'PARALLEL_INIT test failed.'
  END IF
  
  DO i = 1, 5
    input(i) = i * 1.0
    output(i) = 0.0
  END DO
  
  CALL PARALLEL_SUM(input, output, 5)
  IF (ALL(output == input)) THEN
    PRINT *, 'PARALLEL_SUM test passed.'
  ELSE
    PRINT *, 'PARALLEL_SUM test failed.'
  END IF
  
  CALL PARALLEL_FINALIZE()
  PRINT *, 'PARALLEL_FINALIZE called successfully.'
END PROGRAM test_parallel_routines