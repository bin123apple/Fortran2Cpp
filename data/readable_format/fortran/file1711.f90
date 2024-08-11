PROGRAM claw_test
  CALL test_kcache()
END PROGRAM claw_test

SUBROUTINE kcache(istart, iend, jstart, jend, sumA6, sumA7, sumA8, sumA9)
  INTEGER, INTENT(IN) :: istart, iend, jstart, jend
  INTEGER :: i, j
  REAL(KIND=8) :: sumA6, sumA7, sumA8, sumA9
  REAL(KIND=8), DIMENSION(istart:iend, jstart:jend) :: array6, array7, array8, array9, data1, data2

  data1(:,:) = 2.0
  data2(:,:) = 3.0

  array6(:, :) = 0.0
  array7(:, :) = 0.0
  array8(:, :) = 0.0
  array9(:, :) = 0.0

  DO i = istart, iend
    array6(i, 1) = 1.0
    array7(i, 1) = 2.0
    array8(i, 1) = 3.0
    array9(i, 1) = 4.0
  END DO

  DO i = istart, iend
    DO j = jstart+1, jend
      data1(i, j-1) = 0.0
      array6(i, j) = array6(i, j-1) * 2.0 + data1(i, j)
      array7(i, j) = array7(i, j-1) * 2.0 + array6(i, j-1) + data1(i, j)
      array8(i, j) = array8(i, j-1) * 2.0 + array6(i, j-1) + array7(i, j-1) + data2(i, j)
      array9(i, j) = array9(i, j-1) * 2.0 + array6(i, j-1) + array8(i, j-1) + data2(i, j)
    END DO
  END DO

  sumA6 = SUM(array6)
  sumA7 = SUM(array7)
  sumA8 = SUM(array8)
  sumA9 = SUM(array9)
END SUBROUTINE kcache

SUBROUTINE test_kcache()
  REAL(KIND=8) :: sumA6, sumA7, sumA8, sumA9
  CALL kcache(1, 10, 1, 20, sumA6, sumA7, sumA8, sumA9)
  PRINT*, "Fortran Test Results:"
  PRINT*, "Sum of array6:", sumA6
  PRINT*, "Sum of array7:", sumA7
  PRINT*, "Sum of array8:", sumA8
  PRINT*, "Sum of array9:", sumA9
END SUBROUTINE test_kcache