PROGRAM test_ppm_data_loadbal
  IMPLICIT NONE

  ! Definition of ppm_kind_double equivalent
  INTEGER, PARAMETER :: ppm_kind_double = SELECTED_REAL_KIND(p=15, r=307)
  
  REAL(ppm_kind_double) :: ppm_loadbal_decomp_cost = 0.0_ppm_kind_double
  INTEGER               :: ppm_loadbal_dcn = 0
  REAL(ppm_kind_double) :: ppm_loadbal_runsum = 0.0_ppm_kind_double
  REAL(ppm_kind_double) :: ppm_loadbal_old_sar = -1.0_ppm_kind_double

  ! Test initialization
  WRITE(*,*) "Testing initialization..."
  IF (ppm_loadbal_decomp_cost /= 0.0_ppm_kind_double) THEN
      WRITE(*,*) "Test failed: ppm_loadbal_decomp_cost not initialized correctly"
  ELSE IF (ppm_loadbal_dcn /= 0) THEN
      WRITE(*,*) "Test failed: ppm_loadbal_dcn not initialized correctly"
  ELSE IF (ppm_loadbal_runsum /= 0.0_ppm_kind_double) THEN
      WRITE(*,*) "Test failed: ppm_loadbal_runsum not initialized correctly"
  ELSE IF (ppm_loadbal_old_sar /= -1.0_ppm_kind_double) THEN
      WRITE(*,*) "Test failed: ppm_loadbal_old_sar not initialized correctly"
  ELSE
      WRITE(*,*) "Initialization test passed."
  END IF

  ! Test modification and retrieval
  WRITE(*,*) "Testing modification and retrieval..."
  ppm_loadbal_decomp_cost = 10.0_ppm_kind_double
  ppm_loadbal_dcn = 5
  ppm_loadbal_runsum = 20.0_ppm_kind_double
  ppm_loadbal_old_sar = 30.0_ppm_kind_double
  
  IF (ppm_loadbal_decomp_cost == 10.0_ppm_kind_double .AND. &
      ppm_loadbal_dcn == 5 .AND. &
      ppm_loadbal_runsum == 20.0_ppm_kind_double .AND. &
      ppm_loadbal_old_sar == 30.0_ppm_kind_double) THEN
      WRITE(*,*) "Modification and retrieval test passed."
  ELSE
      WRITE(*,*) "Test failed: Modification or retrieval of variables failed."
  END IF

END PROGRAM test_ppm_data_loadbal