PROGRAM testRemove
  IMPLICIT NONE
  INTEGER, PARAMETER :: natoms = 5
  INTEGER :: natms, i
  DOUBLE PRECISION :: nuc(natoms), coord(3*natoms), coord2(3*natoms), nuc2(natoms)

  ! Initialize arrays
  nuc = (/1, 0, 2, 0, 3/)
  coord = (/1,2,3, 4,5,6, 7,8,9, 10,11,12, 13,14,15/)
  
  ! Call the subroutine
  CALL REMOVE(natoms, natms, nuc, coord, coord2, nuc2)
  
  ! Output results
  PRINT *, 'Filtered NATMS:', natms
  PRINT *, 'Filtered NUC2:'
  DO i = 1, natms
    PRINT *, nuc2(i)
  END DO
  PRINT *, 'Filtered COORD2:'
  DO i = 1, 3*natms
    PRINT *, coord2(i)
  END DO
  
END PROGRAM testRemove

SUBROUTINE REMOVE(NATOMS,NATMS,NUC,COORD,COORD2,NUC2)
  IMPLICIT NONE
  INTEGER, INTENT(IN) :: NATOMS
  INTEGER, INTENT(OUT) :: NATMS
  DOUBLE PRECISION, INTENT(IN) :: NUC(NATOMS), COORD(3*NATOMS)
  DOUBLE PRECISION, INTENT(OUT) :: COORD2(3*NATOMS), NUC2(NATOMS)
  INTEGER :: ICNT, IATM, I
  
  ICNT = 0
  DO IATM = 1, NATOMS
     IF (NUC(IATM) /= 0) THEN
        ICNT = ICNT + 1
        NUC2(ICNT) = NUC(IATM)
        DO I = 1, 3
           COORD2((ICNT-1)*3+I) = COORD((IATM-1)*3+I)
        END DO
     END IF
  END DO
  NATMS = ICNT
  
END SUBROUTINE REMOVE