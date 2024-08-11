MODULE vast_kind_param
  INTEGER, PARAMETER :: DOUBLE = SELECTED_REAL_KIND(15, 307)
END MODULE vast_kind_param

MODULE hplusf_I   
INTERFACE
SUBROUTINE hplusf (F, H, NORBS) 
USE vast_kind_param, ONLY: DOUBLE
integer, INTENT(IN) :: NORBS  
real(DOUBLE), DIMENSION(NORBS,NORBS), INTENT(INOUT) :: F 
real(DOUBLE), DIMENSION(NORBS,NORBS), INTENT(IN) :: H       
END SUBROUTINE  
END INTERFACE 
END MODULE

SUBROUTINE hplusf(F, H, NORBS)
  USE vast_kind_param, ONLY: DOUBLE
  INTEGER, INTENT(IN) :: NORBS
  REAL(DOUBLE), DIMENSION(NORBS, NORBS), INTENT(INOUT) :: F
  REAL(DOUBLE), DIMENSION(NORBS, NORBS), INTENT(IN) :: H
  INTEGER :: i, j
  
  DO i = 1, NORBS
    DO j = 1, NORBS
      F(i, j) = F(i, j) + H(i, j)
    END DO
  END DO
END SUBROUTINE hplusf

PROGRAM test_hplusf
  USE vast_kind_param, ONLY: DOUBLE
  USE hplusf_I
  IMPLICIT NONE
  INTEGER :: NORBS
  REAL(DOUBLE), ALLOCATABLE :: F(:,:), H(:,:)
  INTEGER :: i, j
  LOGICAL :: success

  NORBS = 3
  ALLOCATE(F(NORBS, NORBS))
  ALLOCATE(H(NORBS, NORBS))

  ! Initialize F and H
  F = 0.0_DOUBLE
  H = RESHAPE([1.0_DOUBLE, 2.0_DOUBLE, 3.0_DOUBLE, &
               4.0_DOUBLE, 5.0_DOUBLE, 6.0_DOUBLE, &
               7.0_DOUBLE, 8.0_DOUBLE, 9.0_DOUBLE], &
              SHAPE(F))

  ! Call the subroutine
  CALL hplusf(F, H, NORBS)

  ! Check results
  success = .TRUE.
  DO i = 1, NORBS
    DO j = 1, NORBS
      IF (F(i, j) /= H(i, j)) THEN
        success = .FALSE.
      END IF
    END DO
  END DO

  IF (success) THEN
    PRINT *, "Test passed!"
  ELSE
    PRINT *, "Test failed!"
  END IF

  DEALLOCATE(F)
  DEALLOCATE(H)
END PROGRAM test_hplusf