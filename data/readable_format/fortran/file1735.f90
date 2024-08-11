MODULE ppm_module_fmm_init

CONTAINS

! Assuming these procedures initialize fields in single/double precision and scalar/vector forms
SUBROUTINE ppm_fmm_init_s_sf()
  PRINT *, "Initializing single precision scalar field."
END SUBROUTINE ppm_fmm_init_s_sf

SUBROUTINE ppm_fmm_init_d_sf()
  PRINT *, "Initializing double precision scalar field."
END SUBROUTINE ppm_fmm_init_d_sf

SUBROUTINE ppm_fmm_init_s_vf()
  PRINT *, "Initializing single precision vector field."
END SUBROUTINE ppm_fmm_init_s_vf

SUBROUTINE ppm_fmm_init_d_vf()
  PRINT *, "Initializing double precision vector field."
END SUBROUTINE ppm_fmm_init_d_vf

END MODULE ppm_module_fmm_init

PROGRAM test_ppm_fmm_init
  USE ppm_module_fmm_init
  IMPLICIT NONE

  CALL ppm_fmm_init_s_sf()
  CALL ppm_fmm_init_d_sf()
  CALL ppm_fmm_init_s_vf()
  CALL ppm_fmm_init_d_vf()

  PRINT *, "All initialization routines called successfully."
END PROGRAM test_ppm_fmm_init