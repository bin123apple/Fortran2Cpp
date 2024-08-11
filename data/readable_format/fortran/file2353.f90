MODULE kinds
  IMPLICIT NONE
  INTEGER, PARAMETER :: DP = SELECTED_REAL_KIND(15, 307)
END MODULE kinds

MODULE mp_global
  IMPLICIT NONE
CONTAINS
  SUBROUTINE mp_global_end()
    ! Placeholder for the actual implementation
    PRINT *, "mp_global_end called"
  END SUBROUTINE mp_global_end
END MODULE mp_global

SUBROUTINE stop_code(flag)
  USE kinds, ONLY: DP
  USE mp_global, ONLY: mp_global_end
  IMPLICIT NONE
  LOGICAL :: flag
  CALL mp_global_end()
  IF (flag) THEN
     STOP
  ELSE
     STOP 1
  ENDIF
END SUBROUTINE stop_code

PROGRAM test_stop_code
  IMPLICIT NONE
  LOGICAL :: flag

  ! Test with flag = .TRUE.
  flag = .TRUE.
  CALL stop_code(flag)

  ! Test with flag = .FALSE.
  flag = .FALSE.
  CALL stop_code(flag)
  
END PROGRAM test_stop_code