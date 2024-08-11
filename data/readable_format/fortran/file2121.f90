module constant
    real*8 :: sgam, smue, sram, seps, szero, szero2, somga
end module constant

program test_constant
    use constant
    implicit none

    ! Assign values to the variables
    sgam = 1.0
    smue = 2.0
    sram = 3.0
    seps = 4.0
    szero = 5.0
    szero2 = 6.0
    somga = 7.0

    ! Print the values to verify correctness
    print *, 'sgam:', sgam
    print *, 'smue:', smue
    print *, 'sram:', sram
    print *, 'seps:', seps
    print *, 'szero:', szero
    print *, 'szero2:', szero2
    print *, 'somga:', somga

    ! Check values
    if (sgam /= 1.0) call abort()
    if (smue /= 2.0) call abort()
    if (sram /= 3.0) call abort()
    if (seps /= 4.0) call abort()
    if (szero /= 5.0) call abort()
    if (szero2 /= 6.0) call abort()
    if (somga /= 7.0) call abort()

    print *, 'All tests passed.'
end program test_constant