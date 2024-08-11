PROGRAM Main
  IMPLICIT NONE
  DOUBLE PRECISION X(3), T, H
  INTEGER N, NSTEP

  N = 3
  T = 0.0
  X = (/8.5, 3.1, 1.2/)
  H = 1E-10
  NSTEP = 1

  CALL RK4SYS(N, T, X, H, NSTEP)
END PROGRAM Main

SUBROUTINE XPSYS(X, F)
  DOUBLE PRECISION X(3), F(3)

  F(1) = 10.0 * (X(2) - X(1))
  F(2) = 28.0 * X(1) - X(1) * X(3) - X(2)
  F(3) = X(1) * X(2) - (8.0 / 3.0) * X(3)

  RETURN
END SUBROUTINE XPSYS

SUBROUTINE RK4SYS(N, T, X, H, NSTEP)
  IMPLICIT NONE
  INTEGER N, NSTEP, I, K
  DOUBLE PRECISION T, H, H2, X(N), Y(N), F1(N), F2(N), F3(N), F4(N)

  PRINT *, 'Fortran Stdout: T,X:', T, (X(I), I = 1, N)
  H2 = 0.5 * H

  DO K = 1, NSTEP
    CALL XPSYS(X, F1)
    DO I = 1, N
      Y(I) = X(I) + H2 * F1(I)
    END DO

    CALL XPSYS(Y, F2)
    DO I = 1, N
      Y(I) = X(I) + H2 * F2(I)
    END DO

    CALL XPSYS(Y, F3)
    DO I = 1, N
      Y(I) = X(I) + H * F3(I)
    END DO

    CALL XPSYS(Y, F4)
    DO I = 1, N
      X(I) = X(I) + H * (F1(I) + 2.0 * (F2(I) + F3(I)) + F4(I)) / 6.0
    END DO
  END DO

  PRINT *, 'T,X:', T, (X(I), I = 1, N)
  RETURN
END SUBROUTINE RK4SYS