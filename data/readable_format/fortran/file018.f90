MODULE SAVE_KERNELS_SOURCE_DERIVATIVES__genmod
  ! This module can contain declarations, specifications, etc.
  CONTAINS
    SUBROUTINE SAVE_KERNELS_SOURCE_DERIVATIVES
      PRINT *, "Executing SAVE_KERNELS_SOURCE_DERIVATIVES"
    END SUBROUTINE SAVE_KERNELS_SOURCE_DERIVATIVES
END MODULE SAVE_KERNELS_SOURCE_DERIVATIVES__genmod

PROGRAM main
  USE SAVE_KERNELS_SOURCE_DERIVATIVES__genmod
  CALL SAVE_KERNELS_SOURCE_DERIVATIVES
END PROGRAM main