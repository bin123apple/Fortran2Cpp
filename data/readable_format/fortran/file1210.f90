! LOCALD_mod.f90
MODULE LOCALD_mod
  INTERFACE
    SUBROUTINE LOCALD(X,Y,SEQ,NSEQ,TEXT,MODE)
      IMPLICIT NONE
      INTEGER, INTENT(IN) :: X, Y
      INTEGER, INTENT(OUT) :: SEQ(*), NSEQ
      CHARACTER(LEN=*), INTENT(IN) :: TEXT, MODE
    END SUBROUTINE LOCALD
  END INTERFACE
END MODULE LOCALD_mod

SUBROUTINE LOCALD(X,Y,SEQ,NSEQ,TEXT,MODE)
  IMPLICIT NONE
  INTEGER, INTENT(IN) :: X, Y
  INTEGER, INTENT(OUT) :: SEQ(*), NSEQ
  CHARACTER(LEN=*), INTENT(IN) :: TEXT, MODE
  INTEGER :: I

  NSEQ = Y - X + 1
  DO I = 1, NSEQ
    SEQ(I) = X + I - 1
  END DO
END SUBROUTINE LOCALD

PROGRAM test_LOCALD
  USE LOCALD_mod
  IMPLICIT NONE
  INTEGER :: SEQ(100), NSEQ, X, Y, I
  CHARACTER(LEN=10) :: TEXT, MODE

  X = 1
  Y = 5
  TEXT = "example"
  MODE = "test"

  CALL LOCALD(X, Y, SEQ, NSEQ, TEXT, MODE)

  PRINT *, "NSEQ: ", NSEQ
  PRINT *, "SEQ: "
  DO I = 1, NSEQ
    PRINT *, SEQ(I)
  END DO
END PROGRAM test_LOCALD