PROGRAM test_insert
  IMPLICIT NONE

  INTEGER, DIMENSION(3) :: ILIST
  DOUBLE PRECISION, DIMENSION(3) :: DLIST
  CHARACTER(LEN=10), DIMENSION(3) :: SLIST

  ! Initialize arrays
  ILIST = (/1, 2, 3/)
  DLIST = (/1.1, 2.2, 3.3/)
  SLIST = (/"one      ", "two      ", "three    "/) ! Strings are now padded to have a length of 10

  ! Call the INSERT subroutine
  CALL INSERT(ILIST, DLIST, SLIST)

  PRINT *, 'INSERT subroutine executed successfully.'

CONTAINS

  SUBROUTINE INSERT(ILIST, DLIST, SLIST)
    INTEGER, DIMENSION(*) :: ILIST
    DOUBLE PRECISION, DIMENSION(*) :: DLIST
    CHARACTER(LEN=10), DIMENSION(*) :: SLIST
    ! The subroutine does nothing
  END SUBROUTINE INSERT

END PROGRAM test_insert