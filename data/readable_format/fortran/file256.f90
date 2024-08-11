PROGRAM testINSTEF
  IMPLICIT NONE
  INTEGER :: xext, yext
  REAL, ALLOCATABLE :: image(:,:)
  REAL :: effic
  INTEGER :: i, j

  xext = 3
  yext = 2
  effic = 2.0
  ALLOCATE(image(xext,yext))

  ! Initialize the image array
  DO j = 1, yext
     DO i = 1, xext
        image(i,j) = i + j
     END DO
  END DO
  
  ! Call the INSTEF subroutine
  CALL INSTEF(effic, xext, yext, image)

  ! Print the modified image array
  DO j = 1, yext
     DO i = 1, xext
        PRINT *, 'image(',i,',',j,') = ', image(i,j)
     END DO
  END DO

  DEALLOCATE(image)
END PROGRAM testINSTEF

SUBROUTINE INSTEF (EFFIC,XEXT,YEXT,IMAGE)
  INTEGER XEXT,YEXT
  REAL IMAGE(XEXT,YEXT)
  REAL EFFIC
  DO J=1,YEXT
    DO I=1,XEXT
      IMAGE(I,J)=IMAGE(I,J)*EFFIC
    END DO
  END DO
END