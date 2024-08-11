PROGRAM testDiv1
  IMPLICIT NONE
  INTEGER, PARAMETER :: NX1 = 3, NY1 = 3, NX2 = 3, NY2 = 3, NX3 = 3, NY3 = 3
  REAL, DIMENSION(NX1, NY1) :: array1
  REAL, DIMENSION(NX2, NY2) :: array2
  REAL, DIMENSION(NX3, NY3) :: array3
  INTEGER :: I, J
  
  ! Initialize array1 and array2 with some values
  array1 = RESHAPE([1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0], SHAPE(array1))
  array2 = RESHAPE([1.0, 2.0, 3.0, 4.0, 0.005, 6.0, 7.0, 8.0, 9.0], SHAPE(array2))

  CALL DIV1(NX1, NY1, array1, NX2, NY2, array2, NX3, NY3, array3)

  PRINT *, "Result array3:"
  DO J = 1, NY3
    DO I = 1, NX3
      PRINT *, array3(I, J)
    END DO
  END DO

END PROGRAM testDiv1

SUBROUTINE DIV1(NX1, NY1, ARRAY1, NX2, NY2, ARRAY2, NX3, NY3, ARRAY3)             
  INTEGER :: NX1, NY1, NX2, NY2, NX3, NY3
  REAL, DIMENSION(NX1, NY1) :: ARRAY1
  REAL, DIMENSION(NX2, NY2) :: ARRAY2
  REAL, DIMENSION(NX3, NY3) :: ARRAY3
  INTEGER :: I, J

  DO J = 1, MIN(NY1, NY2, NY3)
    DO I = 1, MIN(NX1, NX2, NX3)
      IF (ARRAY2(I, J) > 0.01) THEN
        ARRAY3(I, J) = ARRAY1(I, J) / ARRAY2(I, J)
      ELSE
        ARRAY3(I, J) = 0.0
      END IF
    END DO
  END DO

  IF (NY3 > MIN(NY1, NY2, NY3)) THEN
    DO J = MIN(NY1, NY2, NY3) + 1, NY3
      DO I = 1, NX3
        ARRAY3(I, J) = 0.0
      END DO
    END DO
  END IF

  IF (NX3 > MIN(NX1, NX2, NX3)) THEN
    DO J = 1, NY3
      DO I = MIN(NX1, NX2, NX3) + 1, NX3
        ARRAY3(I, J) = 0.0
      END DO
    END DO
  END IF

END SUBROUTINE DIV1