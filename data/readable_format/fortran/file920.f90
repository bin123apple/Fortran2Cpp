PROGRAM Main
  IMPLICIT NONE

  ! Define kinds directly in the program
  INTEGER, PARAMETER :: int_kind = SELECTED_INT_KIND(15)
  INTEGER, PARAMETER :: log_kind = KIND(.TRUE.)
  INTEGER, PARAMETER :: real_kind = SELECTED_REAL_KIND(p=6, r=37)
  INTEGER, PARAMETER :: char_len = 30

  ! Define the grid type
  TYPE :: grid
    INTEGER(int_kind)             :: tdm, time_step, tstart_yy, tstart_mm, tstart_dd
    INTEGER(int_kind)             :: tend_yy, tend_mm, tend_dd
    INTEGER(int_kind), ALLOCATABLE :: mask(:,:)
    INTEGER(int_kind), ALLOCATABLE :: idm(:), jdm(:), kdm(:)
    LOGICAL(log_kind)             :: dataExist, tilted, orthogrid
    REAL(real_kind)               :: fill_value
    REAL(real_kind), ALLOCATABLE  :: w(:,:), lon(:,:,:), lat(:,:,:), depth(:,:)
    REAL(real_kind), ALLOCATABLE  :: uvel(:,:,:,:), vvel(:,:,:,:), wvel(:,:,:,:)
    REAL(real_kind), ALLOCATABLE  :: temp(:,:,:,:), saln(:,:,:,:), dens(:,:,:,:), ssh(:,:,:)
    REAL(real_kind), ALLOCATABLE  :: mld(:,:,:), angle(:,:,:)
    CHARACTER(len=char_len)       :: fnameold, time_units, uname, vname, wname
    CHARACTER(len=char_len)       :: densname, salnname, tempname
  END TYPE grid

  TYPE(grid) :: testGrid

  ! Main program to test
  CALL testProcedure

CONTAINS

  SUBROUTINE testProcedure
    ! Use testGrid here and manipulate or print values to test
    testGrid%tdm = 10
    testGrid%time_step = 5
    testGrid%dataExist = .TRUE.
    testGrid%fill_value = 1.23
    testGrid%fnameold = "test_name"

    PRINT *, "tdm = ", testGrid%tdm
    PRINT *, "time_step = ", testGrid%time_step
    PRINT *, "dataExist = ", testGrid%dataExist
    PRINT *, "fill_value = ", testGrid%fill_value
    PRINT *, "fnameold = ", testGrid%fnameold
  END SUBROUTINE testProcedure

END PROGRAM Main