PROGRAM testComputeColumn
  IMPLICIT NONE
  REAL, ALLOCATABLE :: t(:,:), q(:,:)
  INTEGER :: nz, nproma, i, j
  LOGICAL :: all_tests_passed

  nz = 2
  nproma = 2
  ALLOCATE(t(nproma, nz))
  ALLOCATE(q(nproma, nz))
  
  ! Initialize arrays
  t = RESHAPE(SOURCE=[1.0, -1.0, 2.0, 4.0], SHAPE=[2, 2])
  q = RESHAPE(SOURCE=[2.0, 2.0, 4.0, 8.0], SHAPE=[2, 2])

  CALL compute_column(nz, q, t, nproma)
  
  ! Check results
  all_tests_passed = .TRUE.
  IF (q(1,1) /= 2.0) all_tests_passed = .FALSE.
  IF (q(1,2) /= 2.0) all_tests_passed = .FALSE.
  IF (q(2,1) /= 2.0) all_tests_passed = .FALSE.
  IF (q(2,2) /= 2.0) all_tests_passed = .FALSE.

  IF (all_tests_passed) THEN
    PRINT *, "All tests passed."
  ELSE
    PRINT *, "Some tests failed."
  END IF

CONTAINS

  SUBROUTINE compute_column ( nz , q , t , nproma )
    INTEGER , INTENT(IN) :: nproma
    INTEGER , INTENT(IN) :: nz
    REAL , INTENT(INOUT) :: t ( :, : )
    REAL , INTENT(INOUT) :: q ( :, : )
    INTEGER :: k
    INTEGER :: proma

    DO k = 1 , nz , 1
      DO proma = 1 , nproma , 1
        IF ( t ( proma , k ) > 0. ) THEN
          q ( proma , k ) = q ( proma , k ) / t ( proma , k )
        END IF
      END DO
    END DO
  END SUBROUTINE compute_column

END PROGRAM testComputeColumn