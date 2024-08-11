PROGRAM superd_test
  IMPLICIT NONE
  
  INTEGER, PARAMETER :: NORBS = 3, NELECS = 2, NUMAT = 2
  REAL(KIND=8), DIMENSION(NORBS,NORBS) :: C = RESHAPE([1.0d0, 2.0d0, 3.0d0, &
                                                       4.0d0, 5.0d0, 6.0d0, &
                                                       7.0d0, 8.0d0, 9.0d0], [NORBS, NORBS])
  REAL(KIND=8), DIMENSION(NORBS) :: EIGS = [1.0d0, 2.0d0, 3.0d0]
  INTEGER, DIMENSION(NUMAT) :: NAT = [1, 2]

  ! Call the subroutine superd
  CALL superd(C, EIGS, NORBS, NELECS, NUMAT, NAT)
  
CONTAINS

  SUBROUTINE superd(C, EIGS, NORBS, NELECS, NUMAT, NAT)
    INTEGER, INTENT(IN) :: NORBS, NELECS, NUMAT
    REAL(KIND=8), DIMENSION(NORBS,NORBS), INTENT(IN) :: C
    REAL(KIND=8), DIMENSION(NORBS), INTENT(IN) :: EIGS
    INTEGER, DIMENSION(NUMAT), INTENT(IN) :: NAT
    
    ! Example operation: Print a simple message.
    PRINT *, "superd subroutine called."
    
    ! Replace the above line with the actual functionality of superd
  END SUBROUTINE superd

END PROGRAM superd_test