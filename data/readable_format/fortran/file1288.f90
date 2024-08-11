REAL FUNCTION SNRM2 (N,SX,INCX)                                   
      INTEGER            N,INCX                                         
      REAL               SX(1)                                          
      INTEGER            I,J,NEXT,NN                                    
      REAL               CUTLO,CUTHI,HITEST,SUM,XMAX,ZERO,ONE           
      DATA               ZERO, ONE /0.0E0, 1.0E0/                       
      DATA               CUTLO, CUTHI / 4.441E-16,  1.304E19/           
      IF (N.GT.0) GO TO 5                                               
      SNRM2 = ZERO                                                      
      GO TO 70                                                          
    5 ASSIGN 15 TO NEXT                                                 
      SUM = ZERO                                                        
      NN = N*INCX                                                       
      I = 1                                                             
   10 GO TO NEXT, (15,20,35,40)                                         
   15 IF (ABS(SX(I)).GT.CUTLO) GO TO 55                                 
      ASSIGN 20 TO NEXT                                                 
      XMAX = ZERO                                                       
   20 IF (SX(I).EQ.ZERO) GO TO 65                                       
      IF (ABS(SX(I)).GT.CUTLO) GO TO 55                                 
      ASSIGN 35 TO NEXT                                                 
      GO TO 30                                                          
   25 I = J                                                             
      ASSIGN 40 TO NEXT                                                 
      SUM = (SUM/SX(I))/SX(I)                                           
   30 XMAX = ABS(SX(I))                                                 
      GO TO 45                                                          
   35 IF (ABS(SX(I)).GT.CUTLO) GO TO 50                                 
   40 IF (ABS(SX(I)).LE.XMAX) GO TO 45                                  
      SUM = ONE+SUM*(XMAX/SX(I))**2                                     
      XMAX = ABS(SX(I))                                                 
      GO TO 65                                                          
   45 SUM = SUM+(SX(I)/XMAX)**2                                         
      GO TO 65                                                          
   50 SUM = (SUM*XMAX)*XMAX                                             
   55 HITEST = CUTHI/FLOAT(N)                                           
      DO 60 J=I,NN,INCX                                                 
         IF (ABS(SX(J)).GE.HITEST) GO TO 25                             
   60 SUM = SUM+SX(J)**2                                                
      SNRM2 = SQRT(SUM)                                                 
      GO TO 70                                                          
   65 CONTINUE                                                          
      I = I+INCX                                                        
      IF (I.LE.NN) GO TO 10                                             
      SNRM2 = XMAX*SQRT(SUM)                                            
   70 CONTINUE                                                          
      RETURN                                                            
      END

      PROGRAM testSNRM2
      IMPLICIT NONE
      REAL :: SNRM2
      REAL :: result
      REAL, DIMENSION(5) :: testVector
      INTEGER :: i

      ! Assign values to the test vector
      DO i = 1, 5
         testVector(i) = i * 1.0
      END DO

      ! Call SNRM2 function with N=5, SX=testVector, INCX=1
      result = SNRM2(5, testVector, 1)

      ! Check the result
      IF (ABS(result - 7.41619849) < 0.0001) THEN
          PRINT *, "Test Passed. Result: ", result
      ELSE
          PRINT *, "Test Failed. Expected: 7.41619849, Got: ", result
      END IF
      END PROGRAM testSNRM2