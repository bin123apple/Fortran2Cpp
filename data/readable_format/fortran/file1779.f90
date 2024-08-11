! wannier_new_with_tests.f90
MODULE wannier_new
  IMPLICIT NONE
  INTEGER, PARAMETER :: DP = SELECTED_REAL_KIND(p=15)
  INTEGER, PARAMETER :: ningx = 10
  LOGICAL :: use_wannier = .FALSE.
  LOGICAL :: rkmesh = .FALSE.
  LOGICAL :: plot_wannier = .FALSE.
  LOGICAL :: use_energy_int = .FALSE.
  LOGICAL :: print_wannier_coeff = .FALSE.
  INTEGER :: nwan = 0
  INTEGER :: plot_wan_num = 0
  INTEGER :: plot_wan_spin = 0
  REAL(KIND=DP), ALLOCATABLE :: wan_pot(:,:)
  REAL(KIND=DP), ALLOCATABLE :: wannier_energy(:,:)
  REAL(KIND=DP), ALLOCATABLE :: wannier_occ(:,:,:)
  COMPLEX(KIND=DP), ALLOCATABLE :: pp(:,:)
  COMPLEX(KIND=DP), ALLOCATABLE :: coef(:,:,:)
        
  TYPE ingredient
     INTEGER :: l = 0
     INTEGER :: m = 0
     INTEGER :: iatomwfc = 0
     REAL(KIND=DP) :: c = 0.0_DP
  END TYPE ingredient
  
  TYPE wannier_data
     INTEGER :: iatom = 0
     INTEGER :: ning = 0
     REAL(KIND=DP) :: bands_from = 0.0_DP
     REAL(KIND=DP) :: bands_to = 0.0_DP
     TYPE(ingredient), DIMENSION(ningx) :: ing
  END TYPE wannier_data
  
  TYPE(wannier_data), ALLOCATABLE :: wan_in(:,:)
END MODULE wannier_new

PROGRAM testWannierNew
  USE wannier_new
  IMPLICIT NONE
  INTEGER :: i
  
  ! Initialize variables or call functions here for testing
  ALLOCATE(wan_pot(10,2))
  ALLOCATE(wannier_energy(10,2))
  ALLOCATE(wannier_occ(10,2,2))
  ALLOCATE(pp(10,2))
  ALLOCATE(coef(10,2,2))
  
  ! Populate some arrays with test data
  DO i = 1, 10
    wan_pot(i,:) = i
    wannier_energy(i,:) = i * 0.5
    ! Continue with other initializations as needed
  END DO
  
  PRINT *, "Testing variables..."
  IF (ALL(wan_pot(:,1) == [(i, i=1,10)])) THEN
    PRINT *, "wan_pot first column test passed."
  ELSE
    PRINT *, "wan_pot first column test failed."
  END IF
  
  ! Add more tests as needed
  
  PRINT *, "Testing done."
  
  ! Remember to deallocate arrays if necessary
  DEALLOCATE(wan_pot)
  DEALLOCATE(wannier_energy)
  DEALLOCATE(wannier_occ)
  DEALLOCATE(pp)
  DEALLOCATE(coef)
END PROGRAM testWannierNew