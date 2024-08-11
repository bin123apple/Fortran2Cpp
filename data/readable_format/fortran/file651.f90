PROGRAM claw_test
  IMPLICIT NONE
  INTEGER :: istart = 1
  INTEGER :: iend = 10
  INTEGER :: jstart = 1
  INTEGER :: jend = 20
  CALL kcache(istart, iend, jstart, jend)
END PROGRAM claw_test

SUBROUTINE kcache(istart, iend, jstart, jend)
  INTEGER, INTENT(IN) :: istart, iend, jstart, jend
  INTEGER :: i, j
  REAL(KIND=8), DIMENSION(istart:iend, jstart:jend) :: array6, array7, array8, &
                                                      array9, data1, data2
  REAL(KIND=8) :: sum6, sum7, sum8, sum9

  data1(:,:) = 2.0
  data2(:,:) = 3.0

  array6(:, :) = 0.0
  array7(:, :) = 0.0
  array8(:, :) = 0.0
  array9(:, :) = 0.0

  DO i = istart, iend
    array6(i, jstart) = 1.0
    array7(i, jstart) = 2.0
    array8(i, jstart) = 3.0
    array9(i, jstart) = 4.0
  END DO

  DO i = istart, iend
    DO j = jstart+1, jend
      array6(i,j) = array6(i,j-1) * 2.0 + data1(i,j)
      array7(i,j) = array7(i,j-1) * 2.0 + array6(i,j-1) + data1(i,j)
      array8(i,j) = array8(i,j-1) * 2.0 + array6(i,j-1) + array7(i,j-1) + data2(i,j)
      array9(i,j) = array9(i,j-1) * 2.0 + array6(i,j-1) + array8(i,j-1) + data2(i,j)
    END DO
  END DO

  sum6 = SUM(array6)
  sum7 = SUM(array7)
  sum8 = SUM(array8)
  sum9 = SUM(array9)

  PRINT*, 'Computed sums:'
  PRINT*, sum6
  PRINT*, sum7
  PRINT*, sum8
  PRINT*, sum9
END SUBROUTINE kcache