FUNCTION ITBIT(N,I)
      INTEGER N, I
      DIMENSION NP(26)
      DATA IFIRST/0/
      SAVE IFIRST
      SAVE NP
      IF(IFIRST.EQ.0)  THEN
         IFIRST=1
         NP(1)=1
         DO 10 J=2,26
            NP(J)=2*NP(J-1)
   10    CONTINUE
      ENDIF
      IF(I.GT.0.AND.I.LE.25)  THEN
         ITBIT=MOD(N,NP(I+1))/NP(I)
      ELSE
         ITBIT=0
      ENDIF
      END
      
      PROGRAM TEST_ITBIT
      INTEGER ITBIT
      WRITE(*,*) 'Testing ITBIT...'
      IF (ITBIT(10,2) .EQ. 1) THEN
         WRITE(*,*) 'Test 1 passed.'
      ELSE
         WRITE(*,*) 'Test 1 failed.'
      ENDIF
      
      IF (ITBIT(4,2) .EQ. 0) THEN
         WRITE(*,*) 'Test 2 passed.'
      ELSE
         WRITE(*,*) 'Test 2 failed.'
      ENDIF
      
      IF (ITBIT(1,1) .EQ. 1) THEN
         WRITE(*,*) 'Test 3 passed.'
      ELSE
         WRITE(*,*) 'Test 3 failed.'
      ENDIF
      
      END PROGRAM TEST_ITBIT