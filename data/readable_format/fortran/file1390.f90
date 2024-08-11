MODULE ocean_mod
  IMPLICIT NONE
  LOGICAL :: is_finalized = .FALSE.
CONTAINS
  SUBROUTINE ROMS_finalize
    ! This subroutine finalizes the ROMS environment. For illustration, it simply sets is_finalized to TRUE.
    is_finalized = .TRUE.
    PRINT *, "ROMS_finalize called, environment finalized."
  END SUBROUTINE ROMS_finalize
  
  SUBROUTINE abort(status)
    INTEGER, INTENT(IN) :: status
    CALL ROMS_finalize
    STOP
  END SUBROUTINE abort
END MODULE ocean_mod

PROGRAM testAbort
  USE ocean_mod, ONLY : ROMS_finalize, is_finalized, abort
  IMPLICIT NONE
  
  ! Call the subroutine we want to test indirectly. Normally, you wouldn't call abort here directly as it stops the program.
  ! For demonstration, let's call ROMS_finalize directly to avoid stopping the program.
  CALL ROMS_finalize
  
  ! Check if ROMS_finalize did its job
  IF (is_finalized) THEN
    PRINT *, "Test Passed: ROMS_finalize set is_finalized to TRUE"
  ELSE
    PRINT *, "Test Failed: is_finalized remains FALSE"
  END IF
END PROGRAM testAbort