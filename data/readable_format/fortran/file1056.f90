MODULE UPDATE_VELOC_ACOUSTIC__genmod
  IMPLICIT NONE
  CONTAINS
    SUBROUTINE UPDATE_VELOC_ACOUSTIC(NGLOB, VELOC_OUTER_CORE, ACCEL_OUTER_CORE, DELTATOVER2)
      INTEGER, INTENT(IN) :: NGLOB
      REAL(KIND=4), INTENT(INOUT) :: VELOC_OUTER_CORE(NGLOB)
      REAL(KIND=4), INTENT(IN) :: ACCEL_OUTER_CORE(NGLOB)
      REAL(KIND=4), INTENT(IN) :: DELTATOVER2
      INTEGER :: i
      
      DO i = 1, NGLOB
        VELOC_OUTER_CORE(i) = VELOC_OUTER_CORE(i) + ACCEL_OUTER_CORE(i) * DELTATOVER2
      END DO
    END SUBROUTINE UPDATE_VELOC_ACOUSTIC
END MODULE UPDATE_VELOC_ACOUSTIC__genmod

PROGRAM TestUpdateVelocAcoustic
  USE UPDATE_VELOC_ACOUSTIC__genmod
  IMPLICIT NONE
  INTEGER, PARAMETER :: nglob = 5
  REAL(KIND=4) :: velocOuterCore(nglob)
  REAL(KIND=4) :: accelOuterCore(nglob)
  REAL(KIND=4) :: deltaTover2
  INTEGER :: i
  
  ! Initialize test data
  deltaTover2 = 0.5
  DO i = 1, nglob
    accelOuterCore(i) = i * 0.1
    velocOuterCore(i) = 0.0
  END DO
  
  ! Call the subroutine to update velocities
  CALL UPDATE_VELOC_ACOUSTIC(nglob, velocOuterCore, accelOuterCore, deltaTover2)

  ! Check results
  PRINT *, "Updated velocities:"
  DO i = 1, nglob
    PRINT *, "Velocity(", i, ") = ", velocOuterCore(i)
  END DO
END PROGRAM TestUpdateVelocAcoustic