! A_module.f90
MODULE A
   IMPLICIT NONE

   TYPE T
      INTEGER, ALLOCATABLE :: v(:)
   END TYPE T

   INTEGER :: n = 0

CONTAINS

   SUBROUTINE FOO
      IMPLICIT NONE
      TYPE(T) :: var
      INTEGER :: suma, i

      ALLOCATE(var%v(n))
      ! For testing, let's initialize the array to make the test meaningful
      DO i = 1, n
         var%v(i) = i
      END DO

      suma = SUM(var%v(:))
      PRINT *, "Sum:", suma  ! This would be part of a check in a real test
   END SUBROUTINE FOO

END MODULE A

! Main program for testing
PROGRAM test
    USE A
    IMPLICIT NONE

    n = 5
    CALL FOO
END PROGRAM test