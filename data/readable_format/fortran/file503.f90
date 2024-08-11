PROGRAM LOADF_TEST
      IMPLICIT NONE

      INTEGER :: N1, N2, N3, N4, N5
      PARAMETER (N1=3, N2=5, N3=3, N4=5, N5=5)
      REAL :: A(N1,N2), B(N3,N4), R(3,2,N5)
      INTEGER :: I, J, K

      ! Initialize arrays A and B with some test values
      DO I = 1, N1
         DO J = 1, N2
            A(I,J) = I + J
         END DO
      END DO

      DO I = 1, N3
         DO J = 1, N4
            B(I,J) = I - J
         END DO
      END DO

      ! Call the LOADF subroutine
      CALL LOADF(A,B,R,N1,N2,N3,N4,N5)

      ! Print R array
      DO K = 1, N5
         WRITE(*,*) 'R(:,:,',K,')='
         DO I = 1, 3
            WRITE(*,*) (R(I,J,K), J=1,2)
         END DO
      END DO

      END PROGRAM LOADF_TEST

      SUBROUTINE LOADF(A,B,R,N1,N2,N3,N4,N5)
      REAL A(N1,N2),B(N3,N4),R(3,2,N5)
      INTEGER I
      DO I = 1,N5
      R(1,1,I) = B(1,I)
      R(2,1,I) = B(2,I)
      R(3,1,I) = B(3,I)
      R(1,2,I) = A(1,I)
      R(2,2,I) = A(2,I)
      R(3,2,I) = A(3,I)
      ENDDO
      RETURN
      END