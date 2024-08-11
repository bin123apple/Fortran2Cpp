PROGRAM MAIN
   IMPLICIT NONE
   LOGICAL :: A(10)
   INTEGER :: i

   ! Initialize the array with .TRUE.
   A = .TRUE.

   ! Unit test: Check if all elements are .TRUE.
   DO i=1, SIZE(A)
      IF (.NOT. A(i)) THEN
         PRINT *, "Test Failed at index: ", i
         STOP
      END IF
   END DO
   PRINT *, "All tests passed."
END PROGRAM MAIN