PROGRAM test_sla_SVDSOL
  IMPLICIT NONE
  INTEGER, PARAMETER :: M=2, N=2, MP=2, NP=2
  DOUBLE PRECISION B(M)
  DOUBLE PRECISION U(MP,NP), W(N), V(NP,NP), WORK(N), X(N)
  INTEGER I

  ! Test Case: Simple Case
  B = (/1.0D0, 2.0D0/)
  U = RESHAPE((/1.0D0, 0.0D0, 0.0D0, 1.0D0/), SHAPE(U))
  W = (/1.0D0, 2.0D0/)
  V = RESHAPE((/1.0D0, 0.0D0, 0.0D0, 1.0D0/), SHAPE(V))

  CALL sla_SVDSOL(M, N, MP, NP, B, U, W, V, WORK, X)

  PRINT *, "X:"
  DO I=1, N
    PRINT *, X(I)
  END DO

! Add more test cases as needed

CONTAINS

  SUBROUTINE sla_SVDSOL (M, N, MP, NP, B, U, W, V, WORK, X)
    IMPLICIT NONE

    INTEGER M,N,MP,NP
    DOUBLE PRECISION B(M),U(MP,NP),W(N),V(NP,NP),WORK(N),X(N)

    INTEGER J,I,JJ
    DOUBLE PRECISION S

    DO J=1,N
       S=0D0
       IF (W(J).NE.0D0) THEN
          DO I=1,M
             S=S+U(I,J)*B(I)
          END DO
          S=S/W(J)
       END IF
       WORK(J)=S
    END DO

    DO J=1,N
       S=0D0
       DO JJ=1,N
          S=S+V(J,JJ)*WORK(JJ)
       END DO
       X(J)=S
    END DO

  END SUBROUTINE sla_SVDSOL

END PROGRAM test_sla_SVDSOL