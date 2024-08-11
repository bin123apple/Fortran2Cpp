MODULE facedef
  INTEGER, PARAMETER :: gtype = 0
  INTEGER, PARAMETER :: ndim = 2
  INTEGER, PARAMETER :: nfael = 3
  INTEGER, PARAMETER :: nnofa = 2
  INTEGER, PARAMETER :: nelem_max = 1000
  INTEGER, PARAMETER :: nface_max = 1000
  INTEGER, PARAMETER :: npoin_max = 10000
  DOUBLE PRECISION, PARAMETER :: pi = (ATAN(1.0d0)) * 4.0d0
  DOUBLE PRECISION, PARAMETER :: tol = 1.0E-12
  DOUBLE PRECISION, PARAMETER :: leps = 1.0E-6
  DOUBLE PRECISION, PARAMETER :: sin60 = DSIN(pi / 3.0d0)
  DOUBLE PRECISION, PARAMETER :: tan60 = DTAN(pi / 3.0d0)
  DOUBLE PRECISION :: he
  DOUBLE PRECISION :: he2

  TYPE FACE
    SEQUENCE
    INTEGER :: fid
    INTEGER :: eleid
    INTEGER :: state
    DOUBLE PRECISION :: flen
    INTEGER, DIMENSION(nnofa) :: fnode
    DOUBLE PRECISION, DIMENSION(ndim) :: nhat
  END TYPE FACE
END MODULE facedef

PROGRAM test_facedef
  USE facedef
  IMPLICIT NONE

  TYPE(FACE) :: my_face  ! Renamed face to my_face
  LOGICAL :: passed

  my_face%fid = 1
  my_face%eleid = 2
  my_face%state = 0
  my_face%flen = 1.0d0
  my_face%fnode = (/0, 1/)
  my_face%nhat = (/0.0d0, 1.0d0/)

  ! Check if the values are set correctly
  passed = (my_face%fid == 1) .AND. (my_face%eleid == 2) .AND. &
           (my_face%state == 0) .AND. (my_face%flen == 1.0d0) .AND. &
           (ALL(my_face%fnode == (/0, 1/))) .AND. &
           (ALL(my_face%nhat == (/0.0d0, 1.0d0/)))

  IF (passed) THEN
    PRINT *, "Fortran unit test passed."
  ELSE
    PRINT *, "Fortran unit test failed."
  END IF
END PROGRAM test_facedef