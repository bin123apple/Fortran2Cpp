PROGRAM main
  IMPLICIT NONE
  
  ! Variables for testing
  REAL :: result_2ds
  DOUBLE PRECISION :: result_2dd
  REAL :: a_single
  DOUBLE PRECISION :: a_double
  
  ! Initialize test variables
  a_single = 1.0
  a_double = 1.0d0
  
  ! Call the procedures
  CALL ppm_gmm_extend_fwd_2ds(a_single, result_2ds)
  CALL ppm_gmm_extend_fwd_2dd(a_double, result_2dd)
  
  ! Output the results for demonstration
  PRINT *, "Result 2DS: ", result_2ds
  PRINT *, "Result 2DD: ", result_2dd

END PROGRAM main

SUBROUTINE ppm_gmm_extend_fwd_2ds(input, output)
  IMPLICIT NONE
  REAL, INTENT(IN) :: input
  REAL, INTENT(OUT) :: output
  
  ! Assuming a simple operation, e.g., adding 1
  output = input + 1.0
END SUBROUTINE ppm_gmm_extend_fwd_2ds

SUBROUTINE ppm_gmm_extend_fwd_2dd(input, output)
  IMPLICIT NONE
  DOUBLE PRECISION, INTENT(IN) :: input
  DOUBLE PRECISION, INTENT(OUT) :: output
  
  ! Assuming a simple operation, e.g., adding 1
  output = input + 1.0d0
END SUBROUTINE ppm_gmm_extend_fwd_2dd