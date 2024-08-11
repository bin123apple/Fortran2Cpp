PROGRAM TestMuSuth
    IMPLICIT NONE
    REAL :: testTemperature, expected, result
    LOGICAL :: testPassed
    
    ! Define constants and variables used by muSuth
    REAL, PARAMETER :: mu0 = 1.0, Tref = 1.0, Ts = 2.0, ExpoSuth = 0.5, cSuth = 0.5
    
    ! Test case 1: TnoDim < Ts
    testTemperature = 1.5
    expected = mu0 * testTemperature * Tref * cSuth
    result = muSuth(testTemperature)
    testPassed = (ABS(result - expected) < 0.0001)
    WRITE(*,*) "Test case 1 (TnoDim < Ts):", testPassed
    
    ! Test case 2: TnoDim >= Ts
    testTemperature = 3.0
    expected = mu0 * (testTemperature*Tref)**ExpoSuth * (1+Ts) / (testTemperature*Tref+Ts)
    result = muSuth(testTemperature)
    testPassed = (ABS(result - expected) < 0.0001)
    WRITE(*,*) "Test case 2 (TnoDim >= Ts):", testPassed
    
CONTAINS
    
    FUNCTION muSuth(T) RESULT(muSuthValue)
        REAL, INTENT(IN) :: T
        REAL :: muSuthValue
        REAL :: TnoDim
        TnoDim = T * Tref
        IF (TnoDim >= Ts) THEN
            muSuthValue = mu0 * TnoDim**ExpoSuth * (1 + Ts) / (TnoDim + Ts)
        ELSE
            muSuthValue = mu0 * TnoDim * cSuth
        END IF
    END FUNCTION muSuth
END PROGRAM TestMuSuth