! Define the types module
MODULE types
  TYPE :: tp4
    PRIVATE
    REAL :: x
    INTEGER :: i
  END TYPE tp4

  TYPE :: tp3
    REAL :: x
    INTEGER, PRIVATE :: i
  END TYPE tp3

  TYPE :: tp2
    TYPE(tp3) :: t
  END TYPE tp2

  TYPE :: tp1
    INTEGER :: i
    TYPE(tp2) :: t
  END TYPE tp1
END MODULE types

! Define the nml module
MODULE nml
  USE types
  IMPLICIT NONE

  TYPE(tp1) :: t1
  TYPE(tp4) :: t4

  INTEGER, PRIVATE :: i

CONTAINS

  SUBROUTINE y()
    TYPE(tp2) :: y2
    TYPE(tp3) :: y3
    ! Assuming functionality for subroutine y goes here.
  END SUBROUTINE y
END MODULE nml

! Main program starts here
PROGRAM xxx
  USE types
  USE nml
  IMPLICIT NONE

  TYPE :: tp5
    TYPE(tp4) :: t
  END TYPE tp5

  TYPE(tp5) :: t5

CONTAINS

  SUBROUTINE z()
    ! Assuming functionality for subroutine z goes here.
  END SUBROUTINE z

END PROGRAM xxx