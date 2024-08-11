PROGRAM test_ppm_gmm_march_fwd
    IMPLICIT NONE

    CALL ppm_gmm_march_fwd_2ds()
    CALL ppm_gmm_march_fwd_2dd()
    CALL ppm_gmm_march_fwd_3ds()
    CALL ppm_gmm_march_fwd_3dd()

    PRINT *, "All tests executed."

CONTAINS

    SUBROUTINE ppm_gmm_march_fwd_2ds()
        PRINT *, "Executing 2D, single precision version."
    END SUBROUTINE ppm_gmm_march_fwd_2ds

    SUBROUTINE ppm_gmm_march_fwd_2dd()
        PRINT *, "Executing 2D, double precision version."
    END SUBROUTINE ppm_gmm_march_fwd_2dd

    SUBROUTINE ppm_gmm_march_fwd_3ds()
        PRINT *, "Executing 3D, single precision version."
    END SUBROUTINE ppm_gmm_march_fwd_3ds

    SUBROUTINE ppm_gmm_march_fwd_3dd()
        PRINT *, "Executing 3D, double precision version."
    END SUBROUTINE ppm_gmm_march_fwd_3dd

END PROGRAM test_ppm_gmm_march_fwd