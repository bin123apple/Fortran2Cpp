MODULE injection
  DOUBLE PRECISION    :: RCM_injection=0., ZCM_injection=0., Rwidth_injection=0., Zwidth_injection=0., &
                         XCM_injection=0., YCM_injection=0., Xwidth_injection=0., Ywidth_injection=0., &
                         alpha0 = 0., beta0 = 0., V0 = 0., devalpha = 0., devbeta = 0., devV = 0.
  CHARACTER(LEN=10)   :: inject_type_pos='pointlike', inject_type_vel='stationary'
  LOGICAL             :: inject_coord_cart=.FALSE., inject_coord_cyl=.FALSE., inject_coord_tilt=.FALSE., rand_seed = .TRUE.
END MODULE injection

PROGRAM test_injection
  USE injection
  IMPLICIT NONE

  ! Test the initialization of module variables
  IF (RCM_injection /= 0.0) PRINT *, 'Test failed for RCM_injection'
  IF (ZCM_injection /= 0.0) PRINT *, 'Test failed for ZCM_injection'
  IF (alpha0 /= 0.0) PRINT *, 'Test failed for alpha0'
  IF (TRIM(inject_type_pos) /= 'pointlike') PRINT *, 'Test failed for inject_type_pos'
  IF (inject_coord_cart .NEQV. .FALSE.) PRINT *, 'Test failed for inject_coord_cart'
  IF (inject_coord_cyl .NEQV. .FALSE.) PRINT *, 'Test failed for inject_coord_cyl'
  IF (inject_coord_tilt .NEQV. .FALSE.) PRINT *, 'Test failed for inject_coord_tilt'
  IF (rand_seed .NEQV. .TRUE.) PRINT *, 'Test failed for rand_seed'
  PRINT *, 'All tests passed.'

END PROGRAM test_injection