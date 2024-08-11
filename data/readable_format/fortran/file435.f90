PROGRAM test_hmuf
  IMPLICIT NONE
  INTEGER, PARAMETER :: dp = kind(1.0d0)
  INTEGER, PARAMETER :: NORBS=2, NUMAT=3
  REAL(dp) :: H1(NORBS,NORBS)
  REAL(dp) :: COORD(3,NUMAT)
  INTEGER :: NFIRST(NUMAT), NLAST(NUMAT), NAT(NUMAT)
  INTEGER :: ID

  ! Initialize test data
  ID = 1
  H1 = RESHAPE([1.0_dp, 2.0_dp, &
                3.0_dp, 4.0_dp], &
               SHAPE=[NORBS, NORBS])
  COORD = RESHAPE([1.0_dp, 4.0_dp, 7.0_dp, &
                   2.0_dp, 5.0_dp, 8.0_dp, &
                   3.0_dp, 6.0_dp, 9.0_dp], &
                   SHAPE=[3, NUMAT])
  NFIRST = [1, 2, 3]
  NLAST = [2, 3, 4]
  NAT = [1, 1, 1]

  ! Call the subroutine
  CALL hmuf(H1, ID, COORD, NFIRST, NLAST, NAT, NORBS, NUMAT)

  ! Output results for verification
  PRINT *, "H1 after hmuf call:"
  PRINT *, H1
  PRINT *, "COORD:"
  PRINT *, COORD

CONTAINS

  SUBROUTINE hmuf(H1, ID, COORD, NFIRST, NLAST, NAT, NORBS, NUMAT)
    INTEGER, INTENT(IN) :: ID, NORBS, NUMAT
    REAL(dp), DIMENSION(NORBS,NORBS), INTENT(INOUT) :: H1
    REAL(dp), DIMENSION(3,*), INTENT(IN) :: COORD
    INTEGER, DIMENSION(NUMAT), INTENT(IN) :: NFIRST, NLAST, NAT

    ! Placeholder functionality: Increment each element of H1 by ID
    INTEGER :: i, j
    DO i = 1, NORBS
      DO j = 1, NORBS
        H1(i,j) = H1(i,j) + ID
      END DO
    END DO
  END SUBROUTINE hmuf

END PROGRAM test_hmuf