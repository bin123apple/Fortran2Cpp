PROGRAM main
  IMPLICIT NONE

  REAL :: result_s
  DOUBLE PRECISION :: result_d

  ! Call the single precision version
  CALL ppm_topo_box2subs_s(2.0, 3.0, result_s)
  PRINT *, 'Single precision result: ', result_s

  ! Call the double precision version
  CALL ppm_topo_box2subs_d(2.0d0, 3.0d0, result_d)
  PRINT *, 'Double precision result: ', result_d

CONTAINS

  SUBROUTINE ppm_topo_box2subs_s(a, b, result)
    REAL, INTENT(IN) :: a, b
    REAL, INTENT(OUT) :: result
    result = a * b  ! Example operation
  END SUBROUTINE ppm_topo_box2subs_s

  SUBROUTINE ppm_topo_box2subs_d(a, b, result)
    DOUBLE PRECISION, INTENT(IN) :: a, b
    DOUBLE PRECISION, INTENT(OUT) :: result
    result = a * b  ! Example operation
  END SUBROUTINE ppm_topo_box2subs_d

END PROGRAM main