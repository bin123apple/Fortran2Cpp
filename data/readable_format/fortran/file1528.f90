PROGRAM testNEWPR
      INTEGER, PARAMETER :: maxz=5
      DOUBLE PRECISION PzNew(maxz), PZOLD(maxz), CORR(maxz)
      DOUBLE PRECISION SCALAR
      INTEGER i

      ! Assuming maxz is a constant representing the size of the arrays
      ! Define test values
      DATA PZOLD /1.0, 2.0, 3.0, 4.0, 5.0/
      DATA CORR /0.1, 0.2, 0.3, 0.4, 0.5/
      SCALAR = 2.0

      ! Calling the subroutine (make sure to define or include the subroutine here or in a linked file)
      CALL NEWPR(maxz, PzNew, PZOLD, CORR, SCALAR)

      ! Check the results
      PRINT *, 'PzNew:'
      DO i = 1, maxz
         PRINT *, PzNew(i)
      ENDDO

END PROGRAM testNEWPR

! Assuming the subroutine NEWPR is defined as follows:
SUBROUTINE NEWPR (Nz, PzNew, PZOLD, CORR, SCALAR)
      INTEGER Nz
      DOUBLE PRECISION PzNew(Nz), PZOLD(Nz), CORR(Nz), SCALAR
      INTEGER I

      DO I = 1, Nz
         PzNew(I) = PZOLD(I) + SCALAR * CORR(I)
      ENDDO
END SUBROUTINE NEWPR