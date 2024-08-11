PROGRAM TestLSAME
  LOGICAL LSAME
  CHARACTER*1 CA, CB

  ! Test 1: Identical lowercase characters
  CA = 'a'
  CB = 'a'
  PRINT *, 'Test 1 (a, a): ', LSAME(CA, CB)  ! Expected: TRUE

  ! Test 2: Identical uppercase characters
  CA = 'A'
  CB = 'A'
  PRINT *, 'Test 2 (A, A): ', LSAME(CA, CB)  ! Expected: TRUE

  ! Test 3: Different characters
  CA = 'a'
  CB = 'b'
  PRINT *, 'Test 3 (a, b): ', LSAME(CA, CB)  ! Expected: FALSE

  ! Test 4: Same letter, different case
  CA = 'a'
  CB = 'A'
  PRINT *, 'Test 4 (a, A): ', LSAME(CA, CB)  ! Expected: TRUE
  
END PROGRAM TestLSAME

LOGICAL FUNCTION LSAME (CA, CB)
  CHARACTER CA*1, CB*1
  INTEGER IOFF
  LOGICAL FIRST
  INTRINSIC ICHAR
  SAVE FIRST, IOFF
  DATA FIRST /.TRUE./
  IF (FIRST) THEN
      IOFF = ICHAR('a') - ICHAR('A')
      FIRST = .FALSE.
  END IF
  LSAME = (CA.EQ.CB) .OR. (ICHAR(CA)-IOFF.EQ.ICHAR(CB))
  RETURN
END