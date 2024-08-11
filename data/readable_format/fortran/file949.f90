PROGRAM test_dmzsol
  IMPLICIT REAL*8 (A-H,O-Z)
  INTEGER, PARAMETER :: KD=2, MSTAR=2, N=2
  REAL*8 V(KD,MSTAR), Z(MSTAR), DMZ(KD,N)
  INTEGER I, J

  ! Initialize input arrays
  DATA V /1.0D0, 2.0D0, 3.0D0, 4.0D0/
  DATA Z /2.0D0, 3.0D0/
  DATA DMZ /0.0D0, 0.0D0, 0.0D0, 0.0D0/

  ! Call the subroutine
  CALL DMZSOL(KD, MSTAR, N, V, Z, DMZ)

  ! Output the results
  DO I = 1, N
     DO J = 1, KD
        PRINT *, 'DMZ(', J, ',', I, ') = ', DMZ(J,I)
     END DO
  END DO

END PROGRAM test_dmzsol

! The DMZSOL subroutine definition
SUBROUTINE DMZSOL (KD, MSTAR, N, V, Z, DMZ)
  IMPLICIT REAL*8 (A-H,O-Z)
  INTEGER KD, MSTAR, N, JZ, I, J, L
  REAL*8 V(KD,MSTAR), Z(MSTAR), DMZ(KD,N), FACT

  JZ = 1
  DO I = 1, N
     DO J = 1, MSTAR
        FACT = Z(JZ)
        DO L = 1, KD
           DMZ(L,I) = DMZ(L,I) + FACT * V(L,JZ)
        END DO
        JZ = JZ + 1
     END DO
  END DO
END SUBROUTINE DMZSOL