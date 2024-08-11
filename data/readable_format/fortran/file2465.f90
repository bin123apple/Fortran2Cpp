program test_misc_values
  implicit none

  ! Define the real precision
  integer, parameter :: dp = kind(1.0d0)

  ! Define the MiscValues type
  type MiscValues
    real(dp) :: mv_leafmol
    real(dp) :: mv_soilw
    real(dp) :: mv_soil2g
    real(dp) :: mv_respref
  end type MiscValues

  ! Variable of type MiscValues
  type(MiscValues) :: msv

  ! Set values
  msv%mv_leafmol = 1.1_dp
  msv%mv_soilw = 2.2_dp
  msv%mv_soil2g = 3.3_dp
  msv%mv_respref = 4.4_dp

  ! Print the values to verify
  print *, 'mv_leafmol: ', msv%mv_leafmol
  print *, 'mv_soilw: ', msv%mv_soilw
  print *, 'mv_soil2g: ', msv%mv_soil2g
  print *, 'mv_respref: ', msv%mv_respref

end program test_misc_values