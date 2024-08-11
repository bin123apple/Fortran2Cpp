! Save this as 'moment.f90'
SUBROUTINE moment(data_in,n,skip_id,ave,adev,sdev,var,skew,curt)
  INTEGER, INTENT(IN) :: n, skip_id
  REAL(KIND=8), INTENT(IN) :: data_in(n)
  REAL(KIND=8), INTENT(OUT) :: ave, adev, sdev, var, skew, curt
  INTEGER :: j
  REAL(KIND=8) :: s, ep, p, n_real

  s = 0.0D0
  n_real = DBLE(n)
  DO j = 1, n
    IF (j /= skip_id) THEN
      s = s + data_in(j)
    END IF
  END DO
  ave = s / (n_real - 1.0D0)

  adev = 0.0D0
  var = 0.0D0
  skew = 0.0D0
  curt = 0.0D0
  ep = 0.0D0

  DO j = 1, n
    s = data_in(j) - ave
    ep = ep + s
    adev = adev + ABS(s)
    p = s * s
    var = var + p
    p = p * s
    skew = skew + p
    p = p * s
    curt = curt + p
  END DO

  adev = adev / (n_real - 1.0D0)
  var = (var - ep**2 / n_real) / (n_real - 1.0D0)
  sdev = DSQRT(var)
  IF (var /= 0.0D0) THEN
    skew = skew / ((n_real - 1.0D0) * sdev**3)
    curt = curt / ((n_real - 1.0D0) * var**2) - 3.0D0
  ELSE
    skew = 0.0D0
    curt = 0.0D0
  END IF
END SUBROUTINE moment

PROGRAM test_moment
  IMPLICIT NONE
  INTEGER :: n, skip_id
  REAL(KIND=8), ALLOCATABLE :: data_in(:)
  REAL(KIND=8) :: ave, adev, sdev, var, skew, curt

  n = 5
  skip_id = 2
  ALLOCATE(data_in(n))
  data_in = (/1.0D0, 2.0D0, 3.0D0, 4.0D0, 5.0D0/)

  CALL moment(data_in, n, skip_id, ave, adev, sdev, var, skew, curt)

  PRINT *, 'Fortran Outputs:'
  PRINT *, 'Average:', ave
  PRINT *, 'Absolute Deviation:', adev
  PRINT *, 'Standard Deviation:', sdev
  PRINT *, 'Variance:', var
  PRINT *, 'Skewness:', skew
  PRINT *, 'Kurtosis:', curt

  DEALLOCATE(data_in)
END PROGRAM test_moment