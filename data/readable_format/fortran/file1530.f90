PROGRAM TestSHAPEFUNC3
  USE SHAPEFUNC3__genmod
  IMPLICIT NONE
  INTEGER :: NEL
  REAL(8) :: XII, ETAI, ZETAI, DETJ
  REAL(8), ALLOCATABLE :: R(:), UDISP(:)
  REAL(8), ALLOCATABLE :: DRDX(:,:), DRDXI(:,:), DRDXII(:,:), JAC(:,:), DXDXI(:,:)

  ! Initialize input values
  NEL = 1
  XII = 0.5
  ETAI = 0.5
  ZETAI = 0.5
  ALLOCATE(R((P+1)*(Q+1)*(W+1)))
  ALLOCATE(UDISP((P+1)*(Q+1)*(W+1)*NDS))  ! Corrected to be 1-dimensional
  ALLOCATE(DRDX((P+1)*(Q+1)*(W+1),NDS))
  ALLOCATE(DRDXI((P+1)*(Q+1)*(W+1),NDS))
  ALLOCATE(DRDXII((P+1)*(Q+1)*(W+1),NDS))
  ALLOCATE(JAC(NDS,NDS))
  ALLOCATE(DXDXI(NDS,NDS))

  CALL SHAPEFUNC3(NEL, XII, ETAI, ZETAI, R, DRDX, DRDXI, DRDXII, DETJ, JAC, DXDXI, UDISP)

  PRINT *, "DETJ =", DETJ

  DEALLOCATE(R, UDISP, DRDX, DRDXI, DRDXII, JAC, DXDXI)
END PROGRAM TestSHAPEFUNC3

MODULE SHAPEFUNC3__genmod
  IMPLICIT NONE
  ! Define constants for demonstration, ensure these match your actual definitions
  INTEGER, PARAMETER :: P = 1, Q = 1, W = 1, NDS = 3
CONTAINS
  SUBROUTINE SHAPEFUNC3(NEL,XII,ETAI,ZETAI,R,DRDX,DRDXI,DRDXII,DETJ,JAC,DXDXI,UDISP)
    INTEGER, INTENT(IN) :: NEL
    REAL(8), INTENT(IN) :: XII, ETAI, ZETAI
    REAL(8), INTENT(OUT) :: R((P+1)*(Q+1)*(W+1))
    REAL(8), INTENT(OUT) :: DRDX((P+1)*(Q+1)*(W+1),NDS)
    REAL(8), INTENT(OUT) :: DRDXI((P+1)*(Q+1)*(W+1),NDS)
    REAL(8), INTENT(OUT) :: DRDXII((P+1)*(Q+1)*(W+1),NDS)
    REAL(8), INTENT(OUT) :: DETJ
    REAL(8), INTENT(OUT) :: JAC(NDS,NDS)
    REAL(8), INTENT(OUT) :: DXDXI(NDS,NDS)
    REAL(8), INTENT(IN) :: UDISP((P+1)*(Q+1)*(W+1)*NDS)
    
    ! Placeholder for subroutine implementation
    DETJ = 1.0  ! Example placeholder computation
  END SUBROUTINE SHAPEFUNC3

END MODULE SHAPEFUNC3__genmod