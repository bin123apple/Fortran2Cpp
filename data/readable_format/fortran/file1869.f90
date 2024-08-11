! CombinedModuleTestProgram.f90
MODULE ps_local_gth_module
  IMPLICIT NONE
  PUBLIC :: init_ps_local_gth

CONTAINS

  SUBROUTINE init_ps_local_gth(Va, NMGL, ielm, GG, vqlg)
    IMPLICIT NONE
    REAL(8), INTENT(IN) :: Va
    INTEGER, INTENT(IN) :: NMGL, ielm
    REAL(8), INTENT(IN) :: GG(NMGL)
    REAL(8), INTENT(OUT) :: vqlg(NMGL)
    REAL(8) :: pi, rloc, const, C1, C2, C3, C4, G, v
    INTEGER :: ig

    ! Parameters for the test (assuming these are the values you'd have from pseudopot_module)
    REAL(8), DIMENSION(4) :: parloc = (/1.0d0, 2.0d0, 3.0d0, 4.0d0/)
    REAL(8) :: Zps = 1.0d0
    REAL(8) :: Rcloc = 1.0d0

    pi = ACOS(-1.0D0)
    const = 1.0D0 / ABS(Va)

    vqlg(:) = 0.0D0

    rloc = Rcloc
    C1 = parloc(1)
    C2 = parloc(2)
    C3 = parloc(3)
    C4 = parloc(4)

    vqlg(1) = const * (2.D0 * pi * Zps * rloc**2 + &
         SQRT((2.D0 * pi)**3) * rloc**3 * (C1 + C2 * 3.D0 + C3 * 15.D0 + C4 * 105.D0))

    DO ig = 2, NMGL
      G = SQRT(GG(ig))
      v = -4.D0 * pi * Zps * EXP(-0.5D0 * (G * rloc)**2) / G**2
      v = v + SQRT((2.D0 * pi)**3) * rloc**3 * EXP(-0.5D0 * (rloc * G)**2) * &
        (C1 + C2 * (3.D0 - (rloc * G)**2) + &
         C3 * (15.D0 - 10.D0 * (rloc * G)**2 + (rloc * G)**4) + &
         C4 * (105.D0 - 105.D0 * (rloc * G)**2 + 21.D0 * (rloc * G)**4 - (rloc * G)**6))
      vqlg(ig) = const * v
    END DO
  END SUBROUTINE init_ps_local_gth

END MODULE ps_local_gth_module

PROGRAM test_ps_local_gth
  USE ps_local_gth_module
  IMPLICIT NONE
  INTEGER, PARAMETER :: NMGL = 5
  REAL(8) :: Va, GG(NMGL), vqlg(NMGL)
  INTEGER :: ielm

  Va = 1.0D0
  ielm = 1  ! Assuming this is used to select parameters, but now it's not needed in this simplified example
  GG = (/1.0D0, 2.0D0, 3.0D0, 4.0D0, 5.0D0/)

  CALL init_ps_local_gth(Va, NMGL, ielm, GG, vqlg)

  PRINT *, "vqlg:", vqlg
END PROGRAM test_ps_local_gth