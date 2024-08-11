PROGRAM TestMorse
  IMPLICIT NONE
  INTEGER, PARAMETER :: natoms = 2
  DOUBLE PRECISION :: X(3*natoms) = (/0.0D0, 0.0D0, 0.0D0, 1.0D0, 0.0D0, 0.0D0/)
  DOUBLE PRECISION :: V(3*natoms)
  DOUBLE PRECISION :: EMORSE
  DOUBLE PRECISION :: rho = 1.0D0, R0 = 1.0D0, A = 1.0D0, boxvec(3) = (/10.0D0, 10.0D0, 10.0D0/), rcut = 2.5D0
  LOGICAL :: GTEST = .TRUE., periodic = .FALSE., use_cutoff = .TRUE.
  
  CALL MORSE(X, V, EMORSE, natoms, rho, R0, A, GTEST, periodic, boxvec, use_cutoff, rcut)
  
  PRINT *, "EMORSE:", EMORSE
  PRINT *, "Forces:", V
END PROGRAM TestMorse

SUBROUTINE MORSE(X, V, EMORSE, natoms, rho, R0, A, GTEST, periodic, boxvec, use_cutoff, rcut)
  IMPLICIT NONE
  INTEGER, INTENT(IN) :: natoms
  DOUBLE PRECISION, INTENT(IN) :: X(3*natoms), rho, R0, A, boxvec(3), rcut
  DOUBLE PRECISION, INTENT(OUT) :: V(3*natoms), EMORSE
  LOGICAL, INTENT(IN) :: GTEST, periodic, use_cutoff
  INTEGER :: J1, J2, J3, J4
  DOUBLE PRECISION :: DIST, R, DUMMY, dx(3), eshift, xmul2
  DOUBLE PRECISION :: iboxvec(3)

  IF (periodic) THEN
     iboxvec(:) = 1.D0 / boxvec(:)
  END IF
  
  IF (use_cutoff) THEN
     eshift = (1.D0 - EXP(rho * (R0 - rcut)))**2 - 1.D0
  END IF

  V(:) = 0.D0
  EMORSE = 0.0D0
  
  DO J1 = 1, natoms
     J3 = 3 * J1 - 2
     DO J2 = J1 + 1, natoms
        J4 = 3 * J2 - 2
        dx(:) = X(J3:J3+2) - X(J4:J4+2)
        IF (periodic) THEN
           dx = dx - boxvec * NINT(dx * iboxvec)
        END IF
        DIST = MAX(SQRT(SUM(dx**2)), 1.D-5)
        
        IF (use_cutoff .AND. DIST >= rcut) THEN
           CYCLE
        END IF
        
        R = EXP(rho * (R0 - DIST))
        DUMMY = R * (R - 2.D0)
        EMORSE = EMORSE + DUMMY - Eshift
        
        IF (GTEST) THEN
           xmul2 = rho * 2.D0 * R * (R - 1.D0) / DIST * A
           V(J3:J3+2) = V(J3:J3+2) - xmul2 * dx
           V(J4:J4+2) = V(J4:J4+2) + xmul2 * dx
        END IF
     END DO
  END DO
  
  EMORSE = EMORSE * A
END SUBROUTINE MORSE