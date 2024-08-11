PROGRAM test_prog

  IMPLICIT NONE
  PROCEDURE(add), POINTER :: forig, fset

  forig => add

  CALL set_ptr(forig,fset)

  ! Test 1: Simple addition test
  CALL assert_equal(forig(1,2), 3, "Test 1")
  CALL assert_equal(fset(1,2), 3, "Test 1")

  ! Test 2: Different values test
  CALL assert_equal(forig(5,7), 12, "Test 2")
  CALL assert_equal(fset(5,7), 12, "Test 2")
  
  ! Test 3: Negative values test
  CALL assert_equal(forig(-3,4), 1, "Test 3")
  CALL assert_equal(fset(-3,4), 1, "Test 3")

  ! Test 4: Zero values test
  CALL assert_equal(forig(0,0), 0, "Test 4")
  CALL assert_equal(fset(0,0), 0, "Test 4")

  PRINT *, "All tests passed."

CONTAINS

  SUBROUTINE set_ptr(f1,f2)
    PROCEDURE(add), POINTER :: f1, f2
    f2 => f1
  END SUBROUTINE set_ptr

  FUNCTION add(a,b)
    INTEGER :: a,b,add
    add = a+b
  END FUNCTION add

  SUBROUTINE assert_equal(value, expected, test_label)
    INTEGER, INTENT(IN) :: value, expected
    CHARACTER(*), INTENT(IN) :: test_label
    IF (value /= expected) THEN
      PRINT *, "Test failed - ", test_label, ": Expected ", expected, " but got ", value
      STOP
    END IF
  END SUBROUTINE assert_equal

END PROGRAM test_prog