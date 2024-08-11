program test_chgtemp
    implicit none

    ! Declare the function and its return type
    real :: chgtemp
    external :: chgtemp

    real :: stationelev, cellelev, result, expected

    ! Test case 1
    stationelev = 1500.0
    cellelev = 1000.0
    expected = 0.0065 * (stationelev - cellelev)
    result = chgtemp(stationelev, cellelev)
    if (abs(result - expected) < 1e-6) then
        print *, 'Test case 1 passed'
    else
        print *, 'Test case 1 failed: ', result
    end if

    ! Test case 2
    stationelev = 2000.0
    cellelev = 1500.0
    expected = 0.0065 * (stationelev - cellelev)
    result = chgtemp(stationelev, cellelev)
    if (abs(result - expected) < 1e-6) then
        print *, 'Test case 2 passed'
    else
        print *, 'Test case 2 failed: ', result
    end if

end program test_chgtemp

real function chgtemp(stationelev, cellelev)
    implicit none
    real :: stationelev, cellelev

    chgtemp = 0.0065 * (stationelev - cellelev)
end function chgtemp