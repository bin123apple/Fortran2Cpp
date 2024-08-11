MODULE Precision

  IMPLICIT NONE
  
  INTEGER, PARAMETER :: B1Ki = SELECTED_INT_KIND(2)
  INTEGER, PARAMETER :: B2Ki = SELECTED_INT_KIND(4)
  INTEGER, PARAMETER :: B4Ki = SELECTED_INT_KIND(9)
  INTEGER, PARAMETER :: B8Ki = SELECTED_INT_KIND(18)
  
  INTEGER, PARAMETER :: QuKi = SELECTED_REAL_KIND(20, 500)
  INTEGER, PARAMETER :: R8Ki = SELECTED_REAL_KIND(14, 300)
  INTEGER, PARAMETER :: SiKi = SELECTED_REAL_KIND(6, 30)
  
  INTEGER, PARAMETER :: BYTES_IN_SiKi = 4
  INTEGER, PARAMETER :: BYTES_IN_R8Ki = 8
  INTEGER, PARAMETER :: BYTES_IN_QuKi = 16

  INTEGER, PARAMETER :: IntKi = B4Ki
  INTEGER, PARAMETER :: BYTES_IN_INT = 4

  ! Manually set these for desired precision, mimicking the effect of conditional compilation
  INTEGER, PARAMETER :: ReKi = SiKi
  INTEGER, PARAMETER :: DbKi = R8Ki
  INTEGER, PARAMETER :: BYTES_IN_REAL = BYTES_IN_SiKi
  INTEGER, PARAMETER :: BYTES_IN_DBL = BYTES_IN_R8Ki

END MODULE Precision

PROGRAM testPrecision
  USE Precision
  IMPLICIT NONE
  
  PRINT *, "B1Ki should be capable of 2 digits:", B1Ki
  PRINT *, "B2Ki should be capable of 4 digits:", B2Ki
  PRINT *, "B4Ki should be capable of 9 digits:", B4Ki
  PRINT *, "B8Ki should be capable of 18 digits:", B8Ki
  
  PRINT *, "Bytes in SiKi:", BYTES_IN_SiKi
  PRINT *, "Bytes in R8Ki:", BYTES_IN_R8Ki
  PRINT *, "Bytes in QuKi:", BYTES_IN_QuKi

  ! Add more PRINT statements to test other parameters as needed
  
  PRINT *, "Tests completed."

END PROGRAM testPrecision