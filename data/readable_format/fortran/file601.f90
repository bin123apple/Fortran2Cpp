PROGRAM TEST_ELMHES
      IMPLICIT NONE
      INTEGER, PARAMETER :: np=3, n=3
      DOUBLE PRECISION :: A(np,np)
      INTEGER :: i, j

      ! Initialize a sample matrix
      DATA A /1.0D0, 2.0D0, 3.0D0, 4.0D0, 5.0D0, 6.0D0, 7.0D0, 8.0D0, 9.0D0/

      CALL ELMHES(A, n, np)

      PRINT *, 'Transformed matrix A (Fortran):'
      DO i = 1, np
         WRITE(*, '(3F8.2)') (A(i, j), j = 1, np)
      END DO

      STOP
      END PROGRAM TEST_ELMHES

      SUBROUTINE ELMHES(A,N,NP)
      INTEGER, INTENT(IN) :: N, NP
      DOUBLE PRECISION, INTENT(INOUT) :: A(NP,NP)
      INTEGER :: I, J, M
      DOUBLE PRECISION :: X, Y

      IF(N.GT.2)THEN
        DO M=2,N-1
          X=0.0D0
          I=M
          DO J=M,N
            IF(ABS(A(J,M-1)).GT.ABS(X))THEN
              X=A(J,M-1)
              I=J
            ENDIF
          END DO
          IF(I.NE.M)THEN
            DO J=M-1,N
              Y=A(I,J)
              A(I,J)=A(M,J)
              A(M,J)=Y
            END DO
            DO J=1,N
              Y=A(J,I)
              A(J,I)=A(J,M)
              A(J,M)=Y
            END DO
          ENDIF
          IF(X.NE.0.0D0)THEN
            DO I=M+1,N
              Y=A(I,M-1)
              IF(Y.NE.0.0D0)THEN
                Y=Y/X
                A(I,M-1)=Y
                DO J=M,N
                  A(I,J)=A(I,J)-Y*A(M,J)
                END DO
                DO J=1,N
                  A(J,M)=A(J,M)+Y*A(J,I)
                END DO
              ENDIF
            END DO
          ENDIF
        END DO
      ENDIF
      RETURN
      END SUBROUTINE ELMHES