PROGRAM TestINXCA
      INTEGER IDXA, NA, I, IR
      COMMON /CCBLK/ NPP, K, EPS, CNV, NM, NCMPLX, IK

      ! Initialize the common block variables
      NPP = 0
      K = 0
      EPS = 0
      CNV = 0
      NM = 10
      NCMPLX = 0
      IK = 0

      ! Set test values
      I = 15
      IR = 3

      ! Call the subroutine
      CALL INXCA(I, IR, IDXA, NA)

      ! Print the results
      PRINT *, 'IDXA: ', IDXA
      PRINT *, 'NA: ', NA

END PROGRAM TestINXCA

SUBROUTINE INXCA (I, IR, IDXA, NA)
      COMMON /CCBLK/ NPP, K, EPS, CNV, NM, NCMPLX, IK
      INTEGER I, IR, IDXA, NA

      NA = 2**IR
      IDXA = I-NA+1

      IF (I-NM .GE. 0) THEN
        NA = 0
      END IF

      RETURN
END