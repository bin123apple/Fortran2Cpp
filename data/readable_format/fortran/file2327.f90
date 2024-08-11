MODULE Parameters
  INTEGER, PARAMETER :: MX_NM = 100
  INTEGER, PARAMETER :: SRK = SELECTED_REAL_KIND(6, 37)
END MODULE Parameters

MODULE Rods
  TYPE, PUBLIC :: Rod
    ! Dummy type for demonstration purposes
    INTEGER :: dummy
  END TYPE Rod
END MODULE Rods

MODULE Reflectors
  TYPE, PUBLIC :: Reflector
    ! Dummy type for demonstration purposes
    INTEGER :: dummy
  END TYPE Reflector
END MODULE Reflectors

MODULE Cores
  USE Parameters
  USE Rods
  USE Reflectors
  IMPLICIT NONE

  TYPE, PUBLIC :: Core
     CHARACTER(LEN=MX_NM) :: name
     CHARACTER(LEN=MX_NM) :: geom
     CHARACTER(LEN=MX_NM), DIMENSION(3) :: bc
     TYPE(Reflector), DIMENSION(:), ALLOCATABLE :: refs
     TYPE(Rod), DIMENSION(:,:), ALLOCATABLE :: grid
     REAL(KIND=SRK) :: pwr
     REAL(KIND=SRK), DIMENSION(2) :: pitch
   CONTAINS
     PROCEDURE :: init => init_core
     PROCEDURE :: destroy => clear_core
  END TYPE Core

  CONTAINS

  SUBROUTINE init_core(self, name, geom, dimen, pitch, bc)
    CLASS(Core), INTENT(INOUT) :: self
    CHARACTER(LEN=*), INTENT(IN) :: name
    CHARACTER(LEN=*), INTENT(IN) :: geom
    INTEGER, DIMENSION(2), INTENT(IN) :: dimen
    REAL(KIND=SRK), DIMENSION(2), INTENT(IN) :: pitch
    CHARACTER(LEN=*), DIMENSION(3), INTENT(IN) :: bc

    self%name = name
    self%geom = geom
    ALLOCATE(self%grid(dimen(1),dimen(2)))
    self%pitch = pitch
    self%bc = bc
    ! Initializing refs not shown for brevity
  END SUBROUTINE init_core

  SUBROUTINE clear_core(self)
    CLASS(Core), INTENT(INOUT) :: self

    IF (ALLOCATED(self%grid)) THEN
      DEALLOCATE(self%grid)
    END IF
    IF (ALLOCATED(self%refs)) THEN
      DEALLOCATE(self%refs)
    END IF
  END SUBROUTINE clear_core

END MODULE Cores

PROGRAM TestCore
  USE Cores
  IMPLICIT NONE

  TYPE(Core) :: myCore
  CHARACTER(LEN=100) :: name = 'TestCore'
  CHARACTER(LEN=100) :: geom = 'Geometry'
  CHARACTER(LEN=100), DIMENSION(3) :: bc = (/ 'BC1', 'BC2', 'BC3' /)
  INTEGER, DIMENSION(2) :: dimen = (/ 10, 10 /)
  REAL(KIND=SRK), DIMENSION(2) :: pitch = (/ 1.0_SRK, 1.5_SRK /)

  CALL myCore%init(name, geom, dimen, pitch, bc)
  
  PRINT *, 'Core name:', TRIM(myCore%name)
  PRINT *, 'Core geometry:', TRIM(myCore%geom)
  PRINT *, 'Boundary conditions:', TRIM(myCore%bc(1)), TRIM(myCore%bc(2)), TRIM(myCore%bc(3))
  PRINT *, 'Pitch:', myCore%pitch

  CALL myCore%destroy()
  PRINT *, 'Core cleared successfully.'
END PROGRAM TestCore