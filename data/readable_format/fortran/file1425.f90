! This Fortran file contains both the NEWINERTIA subroutine and a test program.
      SUBROUTINE NEWINERTIA(X, MXATMS, NATOMS, SUM)
      IMPLICIT NONE
      INTEGER NATOMS, J1, J3, MXATMS
      DOUBLE PRECISION X(3*MXATMS), XM, YM, ZM, SUM

      XM=0.0D0
      YM=0.0D0
      ZM=0.0D0
      DO J1=1,NATOMS
         XM=XM+X(3*(J1-1)+1)
         YM=YM+X(3*(J1-1)+2)
         ZM=ZM+X(3*(J1-1)+3)
      ENDDO
      XM=XM/NATOMS
      YM=YM/NATOMS
      ZM=ZM/NATOMS

      SUM=0.0D0
      DO J3=1,NATOMS
         SUM=SUM+(X(3*(J3-1)+1)-XM)**2+(X(3*(J3-1)+2)-YM)**2+(X(3*(J3-1)+3)-ZM)**2
      ENDDO
      SUM=2.0D0*SUM

      END

      PROGRAM test_newinertia
      IMPLICIT NONE
      INTEGER, PARAMETER :: MXATMS = 10
      INTEGER :: NATOMS
      DOUBLE PRECISION :: SUM
      DOUBLE PRECISION, DIMENSION(3*MXATMS) :: X
      INTEGER :: I

      ! Initialize test data
      NATOMS = 3
      DO I = 1, NATOMS
        X(3*(I-1)+1) = I * 1.0D0
        X(3*(I-1)+2) = I * 2.0D0
        X(3*(I-1)+3) = I * 3.0D0
      END DO

      ! Call the subroutine
      CALL NEWINERTIA(X, MXATMS, NATOMS, SUM)

      ! Print the result
      PRINT *, 'Test SUM:', SUM
      END PROGRAM test_newinertia