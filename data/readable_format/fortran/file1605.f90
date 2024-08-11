! CorrectFortranProgram.f90
PROGRAM TestFortranProgram
  IMPLICIT NONE
  INTEGER :: A(200, 100, 19)
  LOGICAL :: TestPassed
  INTEGER :: I, J, K

  A = 0
  CALL FOO(A, 200, 100)

  TestPassed = .TRUE.
  DO I = 1, 200
     DO J = 1, 100
        DO K = 1, 19
           IF (A(I, J, K) /= 1) THEN
              TestPassed = .FALSE.
              EXIT
           END IF
        END DO
        IF (.NOT. TestPassed) EXIT
     END DO
     IF (.NOT. TestPassed) EXIT
  END DO

  IF (TestPassed) THEN
     PRINT *, "Fortran Test Passed: All elements are set to 1."
  ELSE
     PRINT *, "Fortran Test Failed: Not all elements are set to 1."
  END IF
END PROGRAM TestFortranProgram

SUBROUTINE FOO(S, L1, L2)
  INTEGER, INTENT(IN) :: L1, L2
  INTEGER, INTENT(INOUT) :: S(L1, L2, 19)
  INTEGER :: I, J, K

  !$OMP PARALLEL DO PRIVATE(I, J, K)
  DO I = 1, L1
     DO J = 1, L2
        DO K = 1, 19
           S(I, J, K) = 1
        END DO
     END DO
  END DO
  !$OMP END PARALLEL DO
END SUBROUTINE FOO