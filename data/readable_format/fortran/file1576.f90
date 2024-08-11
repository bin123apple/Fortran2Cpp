MODULE MEANFLUXES__genmod
  IMPLICIT NONE
CONTAINS
  SUBROUTINE MEANFLUXES(fluxes, n, mean_flux)
    REAL, INTENT(IN) :: fluxes(:)
    INTEGER, INTENT(IN) :: n
    REAL, INTENT(OUT) :: mean_flux
    mean_flux = SUM(fluxes) / REAL(n)
  END SUBROUTINE MEANFLUXES
END MODULE MEANFLUXES__genmod

PROGRAM TestMeanFluxes
  USE MEANFLUXES__genmod
  IMPLICIT NONE
  REAL, DIMENSION(4) :: fluxes = [1.0, 2.0, 3.0, 4.0]
  REAL :: mean_flux
  INTEGER :: n

  n = SIZE(fluxes)
  CALL MEANFLUXES(fluxes, n, mean_flux)
  PRINT *, "The mean flux is: ", mean_flux
END PROGRAM TestMeanFluxes