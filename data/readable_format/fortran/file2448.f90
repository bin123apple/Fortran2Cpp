! Define the subroutine
SUBROUTINE clawpack5_rpt2adv_manifold(ixy,imp,maxm,meqn, &
     mwaves,maux, mbc,mx,ql,qr,aux1,aux2,aux3, &
     asdq,bmasdq,bpasdq)
  IMPLICIT NONE

  INTEGER ixy,imp,maxm,meqn,mwaves,maux,mbc,mx

  DOUBLE PRECISION     ql(meqn, 1-mbc:maxm+mbc)
  DOUBLE PRECISION     qr(meqn, 1-mbc:maxm+mbc)
  DOUBLE PRECISION   asdq(meqn, 1-mbc:maxm+mbc)
  DOUBLE PRECISION bmasdq(meqn, 1-mbc:maxm+mbc)
  DOUBLE PRECISION bpasdq(meqn, 1-mbc:maxm+mbc)
  DOUBLE PRECISION   aux1(maux, 1-mbc:maxm+mbc)
  DOUBLE PRECISION   aux2(maux, 1-mbc:maxm+mbc)
  DOUBLE PRECISION   aux3(maux, 1-mbc:maxm+mbc)

  INTEGER iface, i, i1, m

  iface = 3-ixy
  DO i = 2-mbc,mx+mbc
     i1 = i-2+imp
     DO m = 1,meqn
        bmasdq(m,i) = MIN(aux2(1+iface,i1), 0.d0) * asdq(m,i)
        bpasdq(m,i) = MAX(aux3(1+iface,i1), 0.d0) * asdq(m,i)
     ENDDO
  END DO

  RETURN
END SUBROUTINE clawpack5_rpt2adv_manifold

! Test the subroutine
PROGRAM test_clawpack5_rpt2adv_manifold
  IMPLICIT NONE

  INTEGER, PARAMETER :: meqn = 2
  INTEGER, PARAMETER :: maux = 3
  INTEGER, PARAMETER :: mbc = 2
  INTEGER, PARAMETER :: maxm = 10
  INTEGER, PARAMETER :: mx = 10
  INTEGER, PARAMETER :: ixy = 1, imp = 1

  DOUBLE PRECISION :: ql(meqn, 1-mbc:maxm+mbc)
  DOUBLE PRECISION :: qr(meqn, 1-mbc:maxm+mbc)
  DOUBLE PRECISION :: asdq(meqn, 1-mbc:maxm+mbc)
  DOUBLE PRECISION :: bmasdq(meqn, 1-mbc:maxm+mbc)
  DOUBLE PRECISION :: bpasdq(meqn, 1-mbc:maxm+mbc)
  DOUBLE PRECISION :: aux1(maux, 1-mbc:maxm+mbc)
  DOUBLE PRECISION :: aux2(maux, 1-mbc:maxm+mbc)
  DOUBLE PRECISION :: aux3(maux, 1-mbc:maxm+mbc)
  
  INTEGER :: i, j

  ! Initialize arrays with some test data
  DO j = 1, meqn
     DO i = 1-mbc, maxm+mbc
        ql(j, i) = 1.0
        qr(j, i) = 2.0
        asdq(j, i) = 1.0
        bmasdq(j, i) = 0.0
        bpasdq(j, i) = 0.0
     END DO
  END DO
  
  DO j = 1, maux
     DO i = 1-mbc, maxm+mbc
        aux1(j, i) = 0.0
        aux2(j, i) = 1.0
        aux3(j, i) = 2.0
     END DO
  END DO

  CALL clawpack5_rpt2adv_manifold(ixy, imp, maxm, meqn, 0, maux, mbc, mx, &
       ql, qr, aux1, aux2, aux3, asdq, bmasdq, bpasdq)

  ! Print some results to verify
  PRINT *, "bmasdq:"
  DO j = 1, meqn
     PRINT *, bmasdq(j, 1-mbc:maxm+mbc)
  END DO

  PRINT *, "bpasdq:"
  DO j = 1, meqn
     PRINT *, bpasdq(j, 1-mbc:maxm+mbc)
  END DO

END PROGRAM test_clawpack5_rpt2adv_manifold