PROGRAM testDawson
  IMPLICIT NONE
  REAL :: result
  INTERFACE
      REAL FUNCTION dawson_v()
      END FUNCTION dawson_v
  END INTERFACE
  
  result = dawson_v()
  IF (result == 1.0) THEN
    PRINT *, "Test passed."
  ELSE
    PRINT *, "Test failed."
  END IF
END PROGRAM testDawson

REAL FUNCTION dawson_v()
  IMPLICIT NONE
  dawson_v = 1.0
  ! Here you could call dawsonseries_v inside dawson_v if needed
END FUNCTION dawson_v

! Assuming dawsonseries_v would be used inside dawson_v
! and needed to be separately defined for any reason.
REAL FUNCTION dawsonseries_v()
  IMPLICIT NONE
  dawsonseries_v = 1.0
END FUNCTION dawsonseries_v