PROGRAM TestGDMPGD
  IMPLICIT NONE
  REAL, ALLOCATABLE :: R(:,:), A(:,:), B(:,:)
  INTEGER :: NI, NJ, NB, I, J
  REAL :: CON
  
  ! Example test case parameters
  NI = 4
  NJ = 4
  NB = 1234
  CON = 1.5
  ALLOCATE(R(NI,NJ), A(NI,NJ), B(NI,NJ))
  
  ! Initialize matrices A and B with random numbers
  CALL RANDOM_NUMBER(A)
  CALL RANDOM_NUMBER(B)

  ! Call the subroutine
  CALL GDMPGD(R, A, B, CON, NI, NJ, NB)
  
  ! Print the result
  PRINT *, 'Result R:'
  DO I = 1, NI
    PRINT *, (R(I, J), J=1, NJ)
  END DO
  
  DEALLOCATE(R, A, B)
END PROGRAM TestGDMPGD

SUBROUTINE GDMPGD (R,A,B,CON,NI,NJ,NB)
  REAL R(NI,NJ), A(NI,NJ), B(NI,NJ)
  INTEGER NI, NJ, NB, I, J, IL, JB, IR, JT, KT
  REAL CON

  ASSIGN 20 TO KT
  GO TO 10

  ENTRY GDDVGD(R,A,B,CON,NI,NJ,NB)

10 IL=1+NB/1000
  JB=1+MOD(NB,1000)/100
  IR=NI-MOD(NB,100)/10
  JT=NJ-MOD(NB,10)
  IF (NB.EQ.0) JT = 1
  IF (NB.EQ.0) IR = NI*NJ

  GO TO KT,(20,60)

20 IF (CON.EQ.1.0) GO TO 40
  DO 30 J=JB,JT
  DO 30 I=IL,IR
     R(I,J) = CON * A(I,J) * B(I,J)
30 CONTINUE
  RETURN

40 DO 50 J=JB,JT
  DO 50 I=IL,IR
     R(I,J) = A(I,J) * B(I,J)
50 CONTINUE
  RETURN

60 IF (CON.EQ.1.0) GO TO 80
  DO 70 J=JB,JT
  DO 70 I=IL,IR
     R(I,J) = A(I,J) / B(I,J)
     R(I,J) = CON * R(I,J)
70 CONTINUE
  RETURN

80 DO 90 J=JB,JT
  DO 90 I=IL,IR
     R(I,J) = A(I,J) / B(I,J)
90 CONTINUE
  RETURN

END SUBROUTINE GDMPGD