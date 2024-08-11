MODULE IMFUD_MOD
  IMPLICIT NONE
CONTAINS
  FUNCTION I_IMFUD0(IDA2, NDS4, NDS3) RESULT(I_IMFUDP)
    INTEGER, INTENT(IN) :: NDS4, NDS3
    INTEGER, INTENT(IN) :: IDA2(5,NDS4,NDS3,2)
    INTEGER :: I_IMFUDP(SIZE(IDA2,1), SIZE(IDA2,2), SIZE(IDA2,3), SIZE(IDA2,4))
    I_IMFUDP = 1 - IDA2
  END FUNCTION I_IMFUD0
END MODULE IMFUD_MOD

PROGRAM testIMFUD
  USE IMFUD_MOD
  IMPLICIT NONE
  INTEGER, ALLOCATABLE :: ida2(:,:,:,:), result(:,:,:,:)
  INTEGER :: nds4, nds3, i, j, k, l

  nds4 = 2
  nds3 = 2
  ALLOCATE(ida2(5, nds4, nds3, 2))
  ALLOCATE(result(5, nds4, nds3, 2))

  ! Initialize array with test data
  DO i = 1, 5
    DO j = 1, nds4
      DO k = 1, nds3
        DO l = 1, 2
          ida2(i,j,k,l) = i+j+k+l
        END DO
      END DO
    END DO
  END DO

  ! Call the function
  result = I_IMFUD0(ida2, nds4, nds3)

  ! Print the result for manual verification
  PRINT *, "Result:"
  DO i = 1, SIZE(result, 1)
    DO j = 1, SIZE(result, 2)
      DO k = 1, SIZE(result, 3)
        DO l = 1, SIZE(result, 4)
          PRINT *, "result(", i, ",", j, ",", k, ",", l, ") = ", result(i,j,k,l)
        END DO
      END DO
    END DO
  END DO

  DEALLOCATE(ida2)
  DEALLOCATE(result)
END PROGRAM testIMFUD