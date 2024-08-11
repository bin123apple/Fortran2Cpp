PROGRAM test_mecid
  IMPLICIT NONE
  INTEGER, PARAMETER :: dp = KIND(1.0D0)
  INTEGER, PARAMETER :: nmos = 4 ! Assuming a value for NMOS; adjust as needed
  REAL(KIND=dp), ALLOCATABLE :: EIGS(:), EIGA(:), DIAG(:)
  REAL(KIND=dp) :: GSE
  REAL(KIND=dp), ALLOCATABLE :: XY(:,:,:,:)
  INTEGER :: i, j, k, l, sizeEIGS

  ! Initialize test data
  sizeEIGS = 5
  ALLOCATE(EIGS(sizeEIGS), EIGA(sizeEIGS), DIAG(sizeEIGS))
  EIGS = [1.0_dp, 2.0_dp, 3.0_dp, 4.0_dp, 5.0_dp]
  EIGA = [5.0_dp, 4.0_dp, 3.0_dp, 2.0_dp, 1.0_dp]
  ALLOCATE(XY(nmos, nmos, nmos, nmos))
  XY = 0.0_dp  ! Initialize all elements to 0
  XY(1,1,1,1) = 1.0_dp  ! Set a specific element for testing

  ! Call the subroutine
  CALL mecid(EIGS, GSE, EIGA, DIAG, XY)

  ! Output the results for manual verification
  PRINT *, "GSE:", GSE
  PRINT *, "EIGA:", EIGA
  PRINT *, "DIAG:", DIAG
  PRINT *, "XY(1,1,1,1):", XY(1,1,1,1)

  CONTAINS

  SUBROUTINE mecid(EIGS, GSE, EIGA, DIAG, XY)
    INTEGER, PARAMETER :: dp = KIND(1.0D0)
    INTEGER, PARAMETER :: nmos = 4
    REAL(KIND=dp), DIMENSION(:), INTENT(IN) :: EIGS
    REAL(KIND=dp), INTENT(OUT) :: GSE
    REAL(KIND=dp), DIMENSION(:), INTENT(INOUT) :: EIGA
    REAL(KIND=dp), DIMENSION(:), INTENT(OUT) :: DIAG
    REAL(KIND=dp), DIMENSION(nmos,nmos,nmos,nmos), INTENT(IN) :: XY
    INTEGER :: i

    ! Example implementation (replace with actual logic as needed)
    GSE = SUM(EIGS)
    DO i = 1, SIZE(EIGA)
      EIGA(i) = EIGA(i) + 1.0_dp
    END DO
    DIAG = EIGS * 2.0_dp

    ! Print XY(1,1,1,1) as an example of accessing the 4D array
    PRINT *, "Accessing XY(1,1,1,1) inside subroutine:", XY(1,1,1,1)
  END SUBROUTINE mecid

END PROGRAM test_mecid