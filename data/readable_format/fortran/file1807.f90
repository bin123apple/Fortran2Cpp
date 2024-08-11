MODULE types
  IMPLICIT NONE
  PUBLIC :: t_comm_variable, bbstr

  TYPE t_comm_variable
    TYPE(grid_comm_pattern_type), ALLOCATABLE :: grid_comm_pattern
  END TYPE t_comm_variable

  TYPE grid_comm_pattern_type
    TYPE(send_type), ALLOCATABLE :: send(:)
  END TYPE grid_comm_pattern_type

  TYPE send_type
    INTEGER, ALLOCATABLE :: index_no(:)
  END TYPE send_type

  TYPE bbstr
    ! Assuming some components for illustration
    INTEGER :: dummy
  END TYPE bbstr

END MODULE types

MODULE globals

  USE types

  IMPLICIT NONE

  PRIVATE

  INTEGER, PARAMETER :: base = 23
  REAL :: number = 0
  TYPE(t_comm_variable), ALLOCATABLE :: comm_variable(:)
  TYPE(bbstr) :: bv(2)

  PUBLIC :: set, get, init_comm_variable, comm_variable, bv

CONTAINS

  SUBROUTINE set(new)
    REAL, INTENT(in) :: new
    number = number + base + new
  END SUBROUTINE set

  REAL FUNCTION get()
    get = number
  END FUNCTION get

  SUBROUTINE init_comm_variable()
    INTEGER :: i, j

    ALLOCATE(comm_variable(2))
    DO i = 1, 2
      ALLOCATE(comm_variable(i)%grid_comm_pattern)
      ALLOCATE(comm_variable(i)%grid_comm_pattern%send(2))
      DO j = 1, 2
        ALLOCATE(comm_variable(i)%grid_comm_pattern%send(j)%index_no(2))
      END DO
    END DO
  END SUBROUTINE init_comm_variable

END MODULE globals

PROGRAM main
  USE globals

  CALL set(10.0)
  PRINT *, get()
  CALL init_comm_variable()

  ! Additional code for testing or using the globals module can go here.

END PROGRAM main