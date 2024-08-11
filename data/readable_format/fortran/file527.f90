! Define a module for the subroutine
MODULE clawpack5_routines
    IMPLICIT NONE
    CONTAINS
    ! Put the subroutine here
    SUBROUTINE clawpack5_rpn2(ixy, maxm, meqn, mwaves, maux, mbc, &
         mx, ql, qr, auxl, auxr, wave, s, amdq, apdq)

      IMPLICIT DOUBLE PRECISION (a-h,o-z)

      INTEGER, INTENT(IN) :: ixy, maxm, meqn, mwaves, maux, mbc, mx
      DOUBLE PRECISION, INTENT(IN) :: ql(meqn, 1-mbc:maxm+mbc), qr(meqn, 1-mbc:maxm+mbc)
      DOUBLE PRECISION, INTENT(IN) :: auxl(maux, 1-mbc:maxm+mbc), auxr(maux, 1-mbc:maxm+mbc)
      DOUBLE PRECISION, INTENT(OUT) :: wave(meqn, mwaves, 1-mbc:maxm+mbc)
      DOUBLE PRECISION, INTENT(OUT) :: s(mwaves, 1-mbc:maxm+mbc), amdq(meqn, 1-mbc:maxm+mbc), apdq(meqn, 1-mbc:maxm+mbc)

      DOUBLE PRECISION delta(3)
      DOUBLE PRECISION rho, bulk, cc, zz
      INTEGER mu, mv, i

      ! Your subroutine's implementation...

    END SUBROUTINE clawpack5_rpn2
END MODULE clawpack5_routines

! Main program
PROGRAM test_clawpack
    USE clawpack5_routines
    IMPLICIT NONE

    ! Define your test variables...
    DOUBLE PRECISION, ALLOCATABLE :: ql(:,:), qr(:,:), auxl(:,:), auxr(:,:), wave(:,:,:), s(:,:), amdq(:,:), apdq(:,:)
    INTEGER :: meqn, mwaves, maux, mbc, mx, maxm, ixy

    ! Initialize your variables...

    ! Call the subroutine
    CALL clawpack5_rpn2(ixy, maxm, meqn, mwaves, maux, mbc, mx, ql, qr, auxl, auxr, wave, s, amdq, apdq)

    ! Add your test or output here...

END PROGRAM test_clawpack