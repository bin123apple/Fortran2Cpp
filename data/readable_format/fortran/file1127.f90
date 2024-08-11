PROGRAM main
  IMPLICIT NONE
  
  ! Call the single precision version
  CALL ppm_fmm_pretraverse_s()

  ! Call the double precision version
  CALL ppm_fmm_pretraverse_d()

CONTAINS

  SUBROUTINE ppm_fmm_pretraverse_s()
    ! Single precision specific implementation
    PRINT *, 'Single precision calculation'
    ! Implement your logic here
  END SUBROUTINE ppm_fmm_pretraverse_s

  SUBROUTINE ppm_fmm_pretraverse_d()
    ! Double precision specific implementation
    PRINT *, 'Double precision calculation'
    ! Implement your logic here
  END SUBROUTINE ppm_fmm_pretraverse_d

END PROGRAM main