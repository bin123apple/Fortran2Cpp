! ASSEMBLYBBAR__genmod.f90
MODULE ASSEMBLYBBAR__genmod
  IMPLICIT NONE
CONTAINS
  SUBROUTINE ASSEMBLYBBAR(NZE, MA, MC, MV)
    INTEGER, INTENT(IN) :: NZE
    REAL(KIND=8), INTENT(IN) :: MA(:,:), MC(:,:), MV(:,:)
    REAL(KIND=8) :: sumMA, sumMC, sumMV
    sumMA = SUM(MA)
    sumMC = SUM(MC)
    sumMV = SUM(MV)
    PRINT *, "Sum of MA: ", sumMA
    PRINT *, "Sum of MC: ", sumMC
    PRINT *, "Sum of MV: ", sumMV
  END SUBROUTINE ASSEMBLYBBAR
END MODULE ASSEMBLYBBAR__genmod

! Test program
PROGRAM test_assemblybbar
  USE ASSEMBLYBBAR__genmod
  IMPLICIT NONE
  REAL(KIND=8), ALLOCATABLE :: MA(:,:), MC(:,:), MV(:,:)
  INTEGER, PARAMETER :: P = 2, Q = 2, W = 2, NDS = 2, NZE = 10
  ALLOCATE(MA((P+1)*(Q+1)*(W+1)*NDS, (P+1)*(Q+1)*(W+1)*NDS))
  ALLOCATE(MC((P+1)*(Q+1)*(W+1)*NDS, P*Q*W))
  ALLOCATE(MV(P*Q*W, P*Q*W))
  MA = 1.0
  MC = 2.0
  MV = 3.0
  CALL ASSEMBLYBBAR(NZE, MA, MC, MV)
  DEALLOCATE(MA, MC, MV)
END PROGRAM test_assemblybbar