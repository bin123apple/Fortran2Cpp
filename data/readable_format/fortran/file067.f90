MODULE source

  IMPLICIT NONE

  TYPE Object
    INTEGER :: i
    REAL :: f
  END TYPE Object

  TYPE Object_to_rename
    INTEGER :: i
  END TYPE Object_to_rename

CONTAINS

  SUBROUTINE object_constructor_i(o, x)
    TYPE(Object), INTENT(OUT) :: o
    INTEGER, INTENT(IN) :: x
    o%i = x
    o%f = 0.0
  END SUBROUTINE object_constructor_i

  SUBROUTINE object_constructor_f(o, f)
    TYPE(Object), INTENT(OUT) :: o
    REAL, INTENT(IN) :: f
    o%i = 0
    o%f = f
  END SUBROUTINE object_constructor_f

  FUNCTION object_add(o, i) RESULT(y)
    TYPE(Object), INTENT(IN) :: o
    INTEGER, INTENT(IN) :: i
    INTEGER :: y
    y = o%i + INT(o%f) + i
  END FUNCTION object_add

  SUBROUTINE Object2_constructor(o, i)
    TYPE(Object_to_rename), INTENT(OUT) :: o
    INTEGER, INTENT(IN) :: i
    o%i = i
  END SUBROUTINE Object2_constructor

  FUNCTION object2_val(o) RESULT(i)
    TYPE(Object_to_rename), INTENT(IN) :: o
    INTEGER :: i
    i = o%i
  END FUNCTION object2_val

END MODULE source

PROGRAM testSource
  USE source
  IMPLICIT NONE

  TYPE(Object) :: obj1, obj2
  TYPE(Object_to_rename) :: obj3
  INTEGER :: result

  CALL object_constructor_i(obj1, 10)
  IF (obj1%i == 10 .AND. obj1%f == 0.0) THEN
    PRINT *, "Test 1 Passed"
  ELSE
    PRINT *, "Test 1 Failed"
  END IF

  CALL object_constructor_f(obj2, 5.5)
  IF (obj2%f == 5.5 .AND. obj2%i == 0) THEN
    PRINT *, "Test 2 Passed"
  ELSE
    PRINT *, "Test 2 Failed"
  END IF

  result = object_add(obj1, 5)
  IF (result == 15) THEN
    PRINT *, "Test 3 Passed"
  ELSE
    PRINT *, "Test 3 Failed"
  END IF

  CALL Object2_constructor(obj3, 3)
  IF (object2_val(obj3) == 3) THEN
    PRINT *, "Test 4 Passed"
  ELSE
    PRINT *, "Test 4 Failed"
  END IF

END PROGRAM testSource