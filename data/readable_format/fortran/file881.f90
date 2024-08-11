PROGRAM main
  IMPLICIT NONE

  ! Test calls
  CALL ppm_gmm_cpt_2ds()
  CALL ppm_gmm_cpt_2dd()
  CALL ppm_gmm_cpt_3ds()
  CALL ppm_gmm_cpt_3dd()

CONTAINS

  ! Dummy implementations of the GMM component processing functions.
  ! Replace these with your actual implementations.

  SUBROUTINE ppm_gmm_cpt_2ds()
    PRINT *, "2D Single Precision GMM Component"
    ! Implementation here...
  END SUBROUTINE ppm_gmm_cpt_2ds

  SUBROUTINE ppm_gmm_cpt_2dd()
    PRINT *, "2D Double Precision GMM Component"
    ! Implementation here...
  END SUBROUTINE ppm_gmm_cpt_2dd

  SUBROUTINE ppm_gmm_cpt_3ds()
    PRINT *, "3D Single Precision GMM Component"
    ! Implementation here...
  END SUBROUTINE ppm_gmm_cpt_3ds

  SUBROUTINE ppm_gmm_cpt_3dd()
    PRINT *, "3D Double Precision GMM Component"
    ! Implementation here...
  END SUBROUTINE ppm_gmm_cpt_3dd

END PROGRAM main