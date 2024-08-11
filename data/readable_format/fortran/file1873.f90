PROGRAM test_ELHEX27_TESTE
  IMPLICIT NONE
  INTEGER :: NEL, INC
  INTEGER, PARAMETER :: P = 2, Q = 2, W = 2, NDS = 3 ! Example values for P, Q, W, NDS
  INTEGER, PARAMETER :: dim = (P+1)*(Q+1)*(W+1)*NDS
  REAL(KIND=8), ALLOCATABLE :: KE(:,:), EL_DDISP(:,:), FINTE(:,:)

  ! Initialize variables
  NEL = 1
  INC = 1
  ALLOCATE(KE(dim,dim), EL_DDISP(dim,1), FINTE(dim,1))
  
  ! Example initialization
  ! Assuming initialization for EL_DDISP here

  ! Call the subroutine
  CALL ELHEX27_TESTE(NEL, KE, EL_DDISP, FINTE, INC)

  ! Output results for manual verification or add checks for expected values
  PRINT *, "FINTE:"
  PRINT *, FINTE

  ! Clean up
  DEALLOCATE(KE, EL_DDISP, FINTE)

CONTAINS

  SUBROUTINE ELHEX27_TESTE(NEL,KE,EL_DDISP,FINTE,INC)
    INTEGER :: NEL, INC
    INTEGER, PARAMETER :: P = 2, Q = 2, W = 2, NDS = 3 ! Example values for P, Q, W, NDS
    INTEGER, PARAMETER :: dim = (P+1)*(Q+1)*(W+1)*NDS
    REAL(KIND=8), INTENT(OUT) :: KE(dim,dim)
    REAL(KIND=8), INTENT(IN) :: EL_DDISP(dim,1)
    REAL(KIND=8), INTENT(OUT) :: FINTE(dim,1)

    ! Subroutine implementation
    ! This is just a placeholder. Implement the logic here.

    PRINT *, "ELHEX27_TESTE subroutine called"
  END SUBROUTINE ELHEX27_TESTE

END PROGRAM test_ELHEX27_TESTE