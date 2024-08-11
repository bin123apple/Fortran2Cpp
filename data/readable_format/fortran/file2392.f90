program test_get_npw2
    implicit none
    integer :: npts, npw2
    real :: signnpw2

    ! Test 1
    npts = 10
    signnpw2 = 1.0
    call get_npw2(npts, signnpw2, npw2)
    print *, "Test 1 - npw2:", npw2

    ! Test 2
    npts = 10
    signnpw2 = -1.0
    call get_npw2(npts, signnpw2, npw2)
    print *, "Test 2 - npw2:", npw2

    ! Test 3
    npts = 16
    signnpw2 = 1.0
    call get_npw2(npts, signnpw2, npw2)
    print *, "Test 3 - npw2:", npw2

    ! Test 4
    npts = 16
    signnpw2 = -1.0
    call get_npw2(npts, signnpw2, npw2)
    print *, "Test 4 - npw2:", npw2

contains

subroutine get_npw2(npts,signnpw2,npw2)
    integer, intent(in) :: npts
    real, intent(in) :: signnpw2
    integer, intent(out) :: npw2
    integer :: npw2_exp, npw2_temp

    npw2_exp = int( alog(float(npts))/alog(2.0) )
    if (signnpw2 < 0.0) then
        npw2 = 2.0**npw2_exp
    else 
        npw2_temp = 2.0**npw2_exp
        if (npw2_temp == npts) then 
            npw2 = npts
        else
            npw2 = 2.0**(npw2_exp+1)
        end if
    end if

    return
end subroutine get_npw2

end program test_get_npw2