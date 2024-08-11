MODULE rk_module
  IMPLICIT NONE
CONTAINS
  SUBROUTINE rk_addtend_dry (t_tend, t_tendf, t_save, rk_step, & 
                              h_diabatic, mut, msft, ide, jde, & 
                              ims, ime, jms, jme, kms, kme, & 
                              its, ite, jts, jte, kts, kte)
    INTEGER, INTENT(IN) :: ide, jde, ims, ime, jms, jme, kms, kme, &
                           its, ite, jts, jte, kts, kte
    INTEGER, INTENT(IN) :: rk_step
    REAL, DIMENSION(ims:ime, kms:kme, jms:jme), INTENT(INOUT) :: t_tend, t_tendf
    REAL, DIMENSION(ims:ime, kms:kme, jms:jme), INTENT(IN) :: t_save, h_diabatic
    REAL, DIMENSION(ims:ime, jms:jme), INTENT(IN) :: mut, msft
    INTEGER :: i, j, k

    DO j = jts, MIN(jte, jde-1)
      DO k = kts, kte-1
        DO i = its, MIN(ite, ide-1)
          IF (rk_step == 1) THEN
            t_tendf(i,k,j) = t_tendf(i,k,j) + t_save(i,k,j)
          END IF
          t_tend(i,k,j) = t_tend(i,k,j) + t_tendf(i,k,j) / msft(i,j) + &
                          mut(i,j) * h_diabatic(i,k,j) / msft(i,j)
        END DO
      END DO
    END DO
  END SUBROUTINE rk_addtend_dry
END MODULE rk_module

PROGRAM test_rk_addtend_dry
  USE rk_module
  IMPLICIT NONE
  INTEGER, PARAMETER :: ide=3, jde=3, ims=1, ime=3, jms=1, jme=3, kms=1, kme=2
  INTEGER, PARAMETER :: its=1, ite=3, jts=1, jte=3, kts=1, kte=2
  INTEGER :: rk_step
  REAL, DIMENSION(ims:ime, kms:kme, jms:jme) :: t_tend, t_tendf, t_save, h_diabatic
  REAL, DIMENSION(ims:ime, jms:jme) :: mut, msft
  INTEGER :: i, j, k

  ! Initialize arrays with some test values
  t_tend = 1.0
  t_tendf = 2.0
  t_save = 0.5
  h_diabatic = 0.4
  mut = 0.3
  msft = 1.0
  rk_step = 1

  CALL rk_addtend_dry(t_tend, t_tendf, t_save, rk_step, h_diabatic, mut, msft, &
                      ide, jde, ims, ime, jms, jme, kms, kme, its, ite, jts, jte, kts, kte)

  ! Print the results to check if they match the expected values
  DO k = kts, kte-1
    DO j = jts, jte-1
      DO i = its, ite-1
        PRINT *, 't_tend(', i, ',', k, ',', j, ') = ', t_tend(i, k, j)
      END DO
    END DO
  END DO
END PROGRAM test_rk_addtend_dry