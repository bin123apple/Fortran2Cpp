! calcrhoelcomp.f90
subroutine calcrhoelcomp(nef, vel, shcon, ielmatf, ntmat_, mi, nefa, nefb)
    implicit none
    integer :: nef, i, imat, ntmat_, mi(*), ielmatf(mi(3), *), nefa, nefb
    real(8) :: t1l, vel(nef, 0:7), shcon(0:3, ntmat_, *)

    do i = nefa, nefb
        t1l = vel(i, 0)
        imat = ielmatf(1, i)
        vel(i, 5) = vel(i, 4) / (shcon(3, 1, imat) * t1l)
    end do
end subroutine calcrhoelcomp


! test_calcrhoelcomp.f90
program test_calcrhoelcomp
    implicit none
    integer, parameter :: nef = 5, ntmat_ = 2, mi(3) = (/nef, 0, 1/)
    real(8) :: vel(nef, 0:7), shcon(0:3, ntmat_, 1)
    integer :: ielmatf(mi(3), nef)
    integer :: nefa, nefb

    ! Initialize test data
    nefa = 1
    nefb = nef

    vel(:, 0) = (/1.0d0, 2.0d0, 3.0d0, 4.0d0, 5.0d0/)
    vel(:, 4) = (/10.0d0, 20.0d0, 30.0d0, 40.0d0, 50.0d0/)
    shcon(3, 1, 1) = 2.0d0
    ielmatf(1, :) = 1

    ! Call the subroutine
    call calcrhoelcomp(nef, vel, shcon, ielmatf, ntmat_, mi, nefa, nefb)

    ! Output result for verification
    print *, 'vel(:,5) after calcrhoelcomp:'
    print *, vel(:, 5)
end program test_calcrhoelcomp