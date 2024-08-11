PROGRAM test
      INTEGER, PARAMETER :: N=4000
      REAL :: A(N,N), B(N,N)
      INTEGER :: I, J
      LOGICAL :: test_passed

      DO J = 1, N
         DO I = 1, N
            A(I,J) = 1.0
            B(I,J) = 1.0
         ENDDO
      ENDDO

      DO J = 1, N
         DO I = 1, N
            A(I,J) = A(I,J) + B(J,I)
         ENDDO
      ENDDO

      test_passed = .TRUE.
      DO J = 1, N
         DO I = 1, N
            IF (A(I, J) /= 2.0 .OR. B(I, J) /= 1.0) THEN
               test_passed = .FALSE.
               EXIT
            ENDIF
         ENDDO
         IF (.NOT. test_passed) EXIT
      ENDDO

      IF (test_passed) THEN
         PRINT *, "Test Passed."
      ELSE
         PRINT *, "Test Failed."
      ENDIF

      STOP
      END