PROGRAM TestUSQUSH
      IMPLICIT NONE
      DOUBLE PRECISION V(10)
      INTEGER I

      ! Initialize the array
      DO I = 1, 10
        V(I) = I
      END DO

      ! Call USQUSH
      CALL USQUSH(V, 4)

      ! Print the modified array
      DO I = 1, 10
        PRINT *, 'V(', I, ') = ', V(I)
      END DO

      END PROGRAM TestUSQUSH

      SUBROUTINE USQUSH(V,ISIZE)
      DOUBLE PRECISION V(ISIZE+6)
      INTEGER I, ISIZE

      DO I = ISIZE, 4, -1
        V(I+6) = V(I)
      END DO

      V(8) = V(3)
      V(7) = V(2)
      V(4) = V(1)
      V(9) = 0D0
      V(6) = 0D0
      V(5) = 0D0

      DO I = 1, 3
        V(I) = 0D0
      END DO

      RETURN
      END