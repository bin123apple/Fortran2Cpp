program test_ynorm
    implicit none

    integer, parameter :: maxsiz = 10
    double precision :: observ(maxsiz), rnorm
    integer :: jstrt, jfins
    integer :: i

    ! Initialize the observ array and other variables
    rnorm = 2.0d0
    jstrt = 2
    jfins = 5

    ! Populate the observ array with initial values
    do i = 1, maxsiz
        observ(i) = dble(i)
    end do

    ! Call the ynorm subroutine
    call ynorm(maxsiz, jstrt, jfins, observ, rnorm)

    ! Print the results to verify the computation
    print *, 'Observ array after calling ynorm:'
    do i = 1, maxsiz
        print *, observ(i)
    end do

end program test_ynorm

subroutine ynorm(maxsiz, jstrt, jfins, observ, rnorm)
    implicit none

    integer maxsiz, jstrt, jfins
    double precision observ(maxsiz), rnorm
    integer i_res

    do 515 i_res = jstrt, jfins
        observ(i_res) = rnorm * observ(i_res)
515 continue
end subroutine ynorm