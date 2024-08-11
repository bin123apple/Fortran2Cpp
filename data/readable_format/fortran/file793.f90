PROGRAM TestX
  IMPLICIT NONE
  TYPE T
    INTEGER :: I
    REAL :: X
  END TYPE T
  TYPE(T), TARGET :: T1(0:3)
  INTEGER, POINTER :: P(:)
  REAL :: SOURCE(4) = [10., 20., 30., 40.]

  T1%I = [1, 2, 3, 4]
  T1%X = SOURCE
  P => T1%I
  CALL Z(P)
  CALL TestZ()
  CALL TestConditions()

CONTAINS
  SUBROUTINE Z(Q)
    INTEGER, POINTER :: Q(:)
    Q(1:3:2) = 999
  END SUBROUTINE Z

  SUBROUTINE TestZ()
    INTEGER, TARGET :: TestArray(4) = [1, 2, 3, 4]
    INTEGER, POINTER :: TestP(:)
    
    TestP => TestArray
    CALL Z(TestP)
    
    IF (ALL(TestArray == [999, 2, 999, 4])) THEN
      PRINT *, "TestZ: PASS"
    ELSE
      PRINT *, "TestZ: FAIL"
    END IF
  END SUBROUTINE TestZ

  SUBROUTINE TestConditions()
    IF (ANY (T1%I .NE. [999, 2, 999, 4])) THEN
      PRINT *, "TestConditions T1%I: FAIL"
    ELSE
      PRINT *, "TestConditions T1%I: PASS"
    END IF
    
    IF (ANY (T1%X .NE. SOURCE)) THEN
      PRINT *, "TestConditions T1%X: FAIL"
    ELSE
      PRINT *, "TestConditions T1%X: PASS"
    END IF
  END SUBROUTINE TestConditions
END PROGRAM TestX