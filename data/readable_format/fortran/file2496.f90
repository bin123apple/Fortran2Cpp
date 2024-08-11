MODULE ppm_module_mesh_finalize
   INTERFACE ppm_mesh_finalize
       MODULE PROCEDURE ppm_mesh_finalize
   END INTERFACE

   CONTAINS

   SUBROUTINE ppm_mesh_finalize()
       PRINT *, 'ppm_mesh_finalize called'
       ! Add actual logic here
   END SUBROUTINE ppm_mesh_finalize

END MODULE ppm_module_mesh_finalize

PROGRAM test_ppm_mesh_finalize
    USE ppm_module_mesh_finalize
    IMPLICIT NONE

    PRINT *, 'Starting test for ppm_mesh_finalize'
    CALL ppm_mesh_finalize()
    PRINT *, 'Finished test for ppm_mesh_finalize'

END PROGRAM test_ppm_mesh_finalize