subroutine checktruecontact(ntie, tieset, tietol, elcon, itruecontact, ncmat_, ntmat_)
    implicit none
    character(len=81) :: tieset(3,*)
    integer :: ntie, itruecontact, i, imat, ncmat_, ntmat_
    real(8) :: tietol(3,*), elcon(0:ncmat_,ntmat_,*)

    itruecontact = 1
    do i = 1, ntie
        if (tieset(1,i)(81:81) == 'C') then
            imat = int(tietol(2,i))
            if (int(elcon(0,1,imat)) == 4) then
                itruecontact = 0
                exit
            endif
        endif
    end do
end subroutine checktruecontact

program testCheckTrueContact
    implicit none
    character(len=81) :: tieset(3,2)
    integer :: ntie, itruecontact, ncmat_, ntmat_
    real(8) :: tietol(3,2)
    real(8) :: elcon(0:1,1,2)

    ntie = 2
    ncmat_ = 1
    ntmat_ = 1
    tieset(:,1) = 'A'
    tieset(:,2) = 'C                                                                            '
    tietol(2,1) = 1.0
    tietol(2,2) = 2.0
    elcon(0,1,1) = 3.0
    elcon(0,1,2) = 4.0

    call checktruecontact(ntie, tieset, tietol, elcon, itruecontact, ncmat_, ntmat_)

    if (itruecontact == 0) then
        print *, "Fortran Test passed."
    else
        print *, "Fortran Test failed."
    endif
end program testCheckTrueContact