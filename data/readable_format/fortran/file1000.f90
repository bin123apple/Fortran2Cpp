! bug468_corrected.f90
program bug468_corrected
    implicit none
    real, allocatable :: hoge(:)
    real :: tmp, pon(10), eps=0.00001
    integer :: nerr, i

    tmp=100.0
    allocate(hoge(10))
    hoge = tmp

    pon = hoge

    nerr=0
    do i=1,10
        if (abs(pon(i)-tmp)>eps) then
            nerr=nerr+1
        endif
    enddo

    ! Unit test: Expecting nerr to be 0 because pon(i) should equal tmp
    if (nerr==0) then
        print *, "Fortran Test Passed."
    else
        print *, "Fortran Test Failed. nerr =", nerr
    end if

end program bug468_corrected