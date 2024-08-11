! File: xxx_test.f90
SUBROUTINE XXX (IL, IU, ivvv)
  implicit none
  integer, INTENT(IN) :: IL, IU
  integer, INTENT(OUT) :: ivvv
  integer :: NXX(14) = (/ 0, 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14 /)
  integer :: ia, ja, iaii
  logical :: qop

  ivvv = 0
  qop = .FALSE.
  iaii = 0

  DO ia = IL, IU
    ja = NXX(ia)
    IF (.NOT. qop .AND. ja > 0) THEN
      iaii = ia
      qop = .TRUE.
    ENDIF

    IF (qop) THEN
      ivvv = ia - iaii + 1
    ENDIF
  ENDDO
END SUBROUTINE XXX

PROGRAM testXXX
  implicit none
  integer :: result

  CALL XXX(1, 3, result)
  IF (result /= 2) THEN
    PRINT *, "Test failed."
  ELSE
    PRINT *, "Test passed."
  ENDIF
END PROGRAM testXXX