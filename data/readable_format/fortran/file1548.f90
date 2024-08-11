program test_compro
    implicit none
    real*8 :: profile(5), emint(5)
    real*8 :: w
    integer :: jfirst, jlast, i

    ! Initialize test data
    profile = (/1.0, 2.0, 3.0, 4.0, 5.0/)
    emint = (/0.5, 1.5, 2.5, 3.5, 4.5/)
    w = 0.5
    jfirst = 1
    jlast = 5

    ! Call subroutine
    call COMPRO(profile, emint, 5, w, jfirst, jlast)

    ! Output results for manual verification
    do i = 1, 5
        print *, "profile(", i, ") = ", profile(i)
    end do

contains

    subroutine COMPRO(PROFILE, EMINT, NFOBR, W, JFIRST, JLAST)
        implicit none
        real*8, intent(inout) :: PROFILE(:)
        real*8, intent(in) :: EMINT(:)
        real*8, intent(in) :: W
        integer, intent(in) :: NFOBR, JFIRST, JLAST
        integer :: K

        do K = 1, NFOBR
            if (JFIRST .EQ. JLAST) then
                PROFILE(K) = EMINT(K)
            else
                PROFILE(K) = PROFILE(K) + W*EMINT(K)
            endif
        enddo

    end subroutine COMPRO

end program test_compro