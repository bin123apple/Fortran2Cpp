MODULE VABPS__genmod

  IMPLICIT NONE

CONTAINS

  SUBROUTINE VABPS(MP, MR, MH, V, VEL)
    INTEGER, INTENT(IN) :: MP, MR, MH
    REAL(KIND=8), INTENT(IN) :: V(MP,MR,MH)
    REAL(KIND=8), INTENT(OUT) :: VEL
    INTEGER :: i, j, k
    REAL(KIND=8) :: sum

    sum = 0.0
    DO k = 1, MH
      DO j = 1, MR
        DO i = 1, MP
          sum = sum + V(i,j,k)
        END DO
      END DO
    END DO
    VEL = sum / (MP*MR*MH)
  END SUBROUTINE VABPS

END MODULE VABPS__genmod

PROGRAM TestVABPS
  USE VABPS__genmod
  IMPLICIT NONE
  INTEGER :: MP, MR, MH
  REAL(KIND=8), ALLOCATABLE :: V(:,:,:)
  REAL(KIND=8) :: VEL

  ! Initialize dimensions
  MP = 2
  MR = 2
  MH = 2
  ALLOCATE(V(MP,MR,MH))
  
  ! Fill in the array with some values
  V = RESHAPE([1.0D0, 2.0D0, 3.0D0, 4.0D0, 5.0D0, 6.0D0, 7.0D0, 8.0D0], SHAPE(V))
  
  ! Call the subroutine
  CALL VABPS(MP, MR, MH, V, VEL)
  
  ! Output the result
  PRINT *, "Computed VEL:", VEL
  
  ! Clean up
  DEALLOCATE(V)

END PROGRAM TestVABPS