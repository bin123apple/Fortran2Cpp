PROGRAM TestTranspose
  IMPLICIT NONE
  DOUBLE PRECISION A(3,3), AT(3,3), B(2,3), BT(3,2), C(1,1), CT(1,1), D(1,3), DT(3,1)
  INTEGER :: i, j

  ! Test 1: Square matrix 3x3
  DATA A /1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0/
  CALL MTRANSP(A, AT, 3, 3, 3, 3)
  PRINT *, 'Square Matrix 3x3 Transpose:'
  DO i = 1, 3
     PRINT *, (AT(i,j), j = 1, 3)
  END DO

  ! Test 2: Non-square matrix 2x3
  DATA B /1.0, 2.0, 3.0, 4.0, 5.0, 6.0/
  CALL MTRANSP(B, BT, 2, 3, 2, 3)
  PRINT *, 'Non-Square Matrix 2x3 Transpose:'
  DO i = 1, 3
     PRINT *, (BT(i,j), j = 1, 2)
  END DO

  ! Test 3: 1x1 Matrix
  DATA C /42.0/
  CALL MTRANSP(C, CT, 1, 1, 1, 1)
  PRINT *, '1x1 Matrix Transpose:'
  PRINT *, CT(1,1)

  ! Test 4: Matrix with one row
  DATA D /1.0, 2.0, 3.0/
  CALL MTRANSP(D, DT, 1, 3, 1, 3)
  PRINT *, 'Matrix with one row Transpose:'
  DO i = 1, 3
     PRINT *, DT(i,1)
  END DO

END PROGRAM TestTranspose

SUBROUTINE MTRANSP(A,AT,NR,NC,NTR,NTC)
  IMPLICIT DOUBLE PRECISION (A-H,O-Z)
  DIMENSION A(NR,NC),AT(NC,NR)
  DO I=1,NTR
  DO J=1,NTC
     AT(J,I)=A(I,J)
  END DO
  END DO
  RETURN
END