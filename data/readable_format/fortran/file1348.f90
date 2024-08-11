PROGRAM testCEL_BLOCK_DATA
      CHARACTER(LEN=80) :: CEL_ERRMSG(0:6)
      COMMON /CEL_DATA/ CEL_ERRMSG

! Initialize error messages
      CEL_ERRMSG(0) = 'Success'
      CEL_ERRMSG(1) = 'Null celprm pointer passed'
      CEL_ERRMSG(2) = 'Invalid projection parameters'
      CEL_ERRMSG(3) = 'Invalid coordinate transformation parameters'
      CEL_ERRMSG(4) = 'Ill-conditioned coordinate transformation parameters'
      CEL_ERRMSG(5) = 'One or more of the (x,y) coordinates were invalid'
      CEL_ERRMSG(6) = 'One or more of the (lng,lat) coordinates were invalid'

! Test: Print the error messages to verify content
      PRINT *, 'Testing CEL_ERRMSG content'
      DO I = 0, 6
         PRINT *, 'Error ', I, ': ', TRIM(CEL_ERRMSG(I))
      END DO

END PROGRAM testCEL_BLOCK_DATA