program testPTOPA
    implicit none

    real :: result

    ! Test case
    result = PTOPA(1013.25)
    print *, 'PTOPA(1013.25) = ', result
    result = PTOPA(800.0)
    print *, 'PTOPA(800) = ', result

contains

    Function PTOPA(P) result(r)
        real, intent(in) :: P
        real :: r
        r = 44331.0 * (1.0 - (P / 1013.25)**0.190263)
    End Function PTOPA

end program testPTOPA