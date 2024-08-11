PROGRAM TestOdrl
  IMPLICIT NONE
  INTEGER, PARAMETER :: nz=5, nw=4
  REAL :: z(nz), wl(nw), c(nz), dtrl(nz,nw)
  INTEGER :: i, j

  ! Initialize some test data
  DO i = 1, nz
    z(i) = i * 1.0
    c(i) = i * 0.1
  END DO

  DO i = 1, nw
    wl(i) = i * 0.5
  END DO

  ! Call the subroutine
  CALL odrl(nz, z, nw, wl, c, dtrl)

  ! Output the results for verification
  DO i = 1, nz
    WRITE(*,*) "dtrl(", i, ",:) =", (dtrl(i,j), j=1,nw)
  END DO

CONTAINS

  SUBROUTINE odrl(nz, z, nw, wl, c, dtrl)
    INTEGER, INTENT(IN) :: nz, nw
    REAL, INTENT(IN) :: z(nz), wl(nw), c(nz)
    REAL, INTENT(OUT) :: dtrl(nz,nw)
    REAL :: srayl, wc, wmicrn, xx
    INTEGER :: iz, iw

    DO iw = 1, nw
       wc = (wl(iw) + wl(MIN(iw+1,nw)))/2.
       wmicrn =  wc/1.E3
       IF( wmicrn <= 0.55) THEN
          xx = 3.6772 + 0.389*wmicrn + 0.09426/wmicrn
       ELSE
          xx = 4. + 0.04
       ENDIF
       srayl = 4.02e-28/(wmicrn**xx)
       DO iz = 1, nz
          dtrl(iz,iw) = c(iz)*srayl
       END DO
    END DO
  END SUBROUTINE odrl

END PROGRAM TestOdrl